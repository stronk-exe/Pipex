/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:19:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/17 14:55:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**path;

	if (ac == 5)
	{
		if (pipe(fd) < 0)
			pipe_error();
		path = get_path(envp);
		if (!path)
			p_throwerror("cmd");
		pid1 = first_child(av, fd, path, envp);
		pid2 = second_child(av, fd, path, envp);
		if (pid1 == -1)
			exit(1);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		main_error();
	return (0);
}
