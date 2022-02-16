/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:52:46 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 18:51:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->pipe_num)
	{
		close(pipex->pipes[i]);
		i++;
	}
}

void	creat_pipes(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->cmd_num - 1))
	{
		if (pipe(&pipex->pipes[2 * i]) < 0)
			throw_error();
		i++;
	}
}

int	ft_exec(char **av, t_pipe *pipex, char **envp)
{
	char	*argv;
	char	**cmd;

	cmd = ft_split(av[pipex->index + pipex->is_here_doc + 2], ' ');
	if (!cmd)
		throw_error();
	argv = get_new_path(pipex->path, cmd);
	if (!argv)
		throw_error();
	execve(argv, cmd, envp);
	return (1);
}

void	create_child(char **av, t_pipe *pipex, char **envp)
{
	int		pid;

	pid = fork();
	if (!pid)
	{
		if (pipex->index == 0)
		{
			dup2(pipex->infile, 0);
			dup2(pipex->pipes[1], 1);
		}
		else if (pipex->index == (pipex->cmd_num - 1))
		{
			dup2(pipex->pipes[2 * pipex->index - 2], 0);
			dup2(pipex->outfile, 1);
		}
		else
		{
			dup2(pipex->pipes[2 * pipex->index - 2], 0);
			dup2(pipex->pipes[2 * pipex->index + 1], 1);
		}
		close_pipes(pipex);
		if (!ft_exec(av, pipex, envp))
			throw_error();
	}
}
