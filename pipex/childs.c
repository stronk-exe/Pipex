/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:15:50 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/17 14:52:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec_1(char **av, char **path, char **envp)
{
	char	*s;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	if (!cmd)
		exit(1);
	s = get_new_path(path, cmd);
	if (!s)
		cmd_error(cmd[0]);
	free(path);
	if (execve(s, cmd, envp) == -1)
		cmd_error(cmd[0]);
	free(s);
	free(cmd);
	return (1);
}

int	ft_exec_2(char **av, char **path, char **envp)
{
	char	*s;
	char	**cmd;

	cmd = ft_split(av[3], ' ');
	if (!cmd)
		exit(1);
	s = get_new_path(path, cmd);
	if (!s)
		cmd_error(cmd[0]);
	free(path);
	if (execve(s, cmd, envp) == -1)
		cmd_error(cmd[0]);
	free(s);
	free(cmd);
	return (1);
}

int	first_child(char **av, int *fd, char **path, char **envp)
{
	int		pid;
	int		infile;

	infile = open(av[1], O_RDONLY, 0000644);
	if (infile < 0)
	{
		perror("open1");
		return (-1);
	}
	pid = fork();
	if (pid < 0)
		p_throwerror("fork");
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		dup2(infile, 0);
		if (!ft_exec_1(av, path, envp))
			p_throwerror("first child");
	}
	return (pid);
}

int	second_child(char **av, int *fd, char **path, char **envp)
{
	int		pid;
	int		outfile;

	outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (outfile < 0)
	{
		perror("open2");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd[0], 0);
		close(fd[1]);
		dup2(outfile, 1);
		if (!ft_exec_2(av, path, envp))
			p_throwerror("second child");
	}
	return (pid);
}
