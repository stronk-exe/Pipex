/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:19:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 18:29:54 by ael-asri         ###   ########.fr       */
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
			return (0);
		path = get_path(envp);
		if (!path)
			throw_error();
		pid1 = first_child(av, fd, path, envp);
		pid2 = second_child(av, fd, path, envp);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		throw_error();
	return (0);
}
