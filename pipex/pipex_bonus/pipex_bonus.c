/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:18:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/11 18:05:38 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	create_child(char **path, char *av, char **envp, int *fd)
{
	pid_t	pid;
	char	**cmd;
	char	*s;

	if (pipe(fd) < 0)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		dup2(fd[0], 0); /// data arrived
		dup2(fd[1], 1);
		cmd = ft_split(av, ' ');
		if (!cmd)
			return (0);
		s = get_new_path(path, cmd);
		if (!s)
			return (0);
		free(path);
		if (execve(s, cmd, envp) == -1)
		{
			perror("Error");
			exit(0);
		}
		// executed
	//	dup2(0, fd[0]); /// data ready to go
	}
	return (fd[1]);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	char	**cmd1;
	char	**cmd2;
	char	*s1;
	char	*s2;
	char	**path;
	char	*line;
	int		n;

	if (ac >= 5)
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (infile < 0 || outfile < 0)
		{
			perror("Error");
			exit(0);
		}
		if (pipe(fd) < 0)
			return (0);
		line = get_path(envp);
		if (!line)
			return (0);
		path = ft_split(line, ':');
		if (!path)
			return (0);
		//////////////////////////////// first child
		
		pid1 = fork();
		if (pid1 < 0)
			return (0);
		if (pid1 == 0)
		{
			dup2(fd[1], 1);
			close(fd[0]);
			dup2(infile, 0);
			cmd1 = ft_split(av[2], ' ');
			if (!cmd1)
				return (0);
			s1 = get_new_path(path, cmd1);
			if (!s1)
				return (0);
			if (execve(s1, cmd1, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		
		//////////////////////////////////////////////
		n = 3;
		while (n < (ac - 1))
		{
			fd[1] = create_child(path, av[n], envp, fd);
			if (pipe(fd) < 0)
				return (0);
			n++;
		}
		//////////////////////////////////////////////
		//////////////////////////////// last child
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		if (pid2 == 0)
		{
			dup2(fd[0], 0);
			close(fd[1]);
			dup2(outfile, 1);
			cmd2 = ft_split(av[3], ' ');
			if (!cmd2)
				return (0);
			s2 = get_new_path(path, cmd2);
			if (!s2)
				return (0);
			free(path);
			if (execve(s2, cmd2, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
