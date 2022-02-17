/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:18:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/17 14:23:22 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	infile_outfile(char **av, int ac, t_pipe *pipex)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex->infile = check_here_doc(av);
		pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0000644);
		pipex->is_here_doc++;
	}
	else
	{
		pipex->infile = open(av[1], O_RDONLY, 0000644);
		pipex->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
	if (pipex->infile < 0 || pipex->outfile < 0)
		p_throwerror("open");
}

void	get_things(int ac, t_pipe *pipex)
{
	pipex->cmd_num = ac - 3 - pipex->is_here_doc;
	pipex->pipe_num = 2 * (pipex->cmd_num - 1);
	pipex->pipes = malloc(sizeof(int) * pipex->pipe_num);
	if (!pipex->pipes)
		malloc_error();
}

int	main(int ac, char **av, char **envp)
{
	t_pipe	pipex;

	if (ac >= 5)
	{
		infile_outfile(av, ac, &pipex);
		pipex.path = get_path(envp);
		if (!pipex.path)
			path_error();
		get_things(ac, &pipex);
		creat_pipes(&pipex);
		pipex.index = 0;
		while (pipex.index < pipex.cmd_num)
		{
			create_child(av, &pipex, envp);
			pipex.index++;
		}
		close_pipes(&pipex);
		while (wait(NULL) != -1)
			;
	}
	else
		main_error();
	return (0);
}
