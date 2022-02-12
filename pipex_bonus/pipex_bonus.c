/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:18:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/12 18:55:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
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
*/
int	h_doc(char **av)
{
	if (!ft_strncmp("here_doc", av[2], 8))
		return (1);
	else
		return (0);
}

void	creat_pipes(int *t, int n)
{
	int	i;

	i = 0;
	printf("n %d\n", n);
	while (i < n)
	{
		if (pipe((t + 2 * i)) < 0)
			exit(1);
		for(int k=0;k<n;k++)
			printf("t[%d] %d\n", k, t[k]);
		i++;
	}
}

void	first_child(char **av, int *t, int n, int infile, char **path, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;
	int		i;
n=0;
	i = 0;
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		printf("av %s\n", av[2]);
		dup2(t[i], 1);
		dup2(infile, 0);
		printf("s %s\n", av[2]);
	//	close(t[i]);
		///////////////////////////////
		cmd = ft_split(av[2], ' ');
		if (!cmd)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		s = get_new_path(path, cmd);
		printf("s %s\n", av[2]);
		if (!s)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		if (execve(s, cmd, envp) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	printf("----------first child\n");
}

void	last_child(char **av, int *t, int n, int outfile, char **path,char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;
	int		i;

	i = 0;
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		dup2(t[i], 0);
		dup2(outfile, 1);
		close(t[i]);
		///////////////////////////////
		cmd = ft_split(av[n+1], ' ');
		if (!cmd)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		s = get_new_path(path, cmd);
		if (!s)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		if (execve(s, cmd, envp) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	printf("---------last child\n");
}

void	regular_child(char **av, int *t, int i, char **path, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;

	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		i++;
		dup2(t[i], 0);
		dup2(t[i], 1);
		///////////////////////////////
		close(t[i]);
		close(t[i]);
		///////////////////////////////
		cmd = ft_split(av[i], ' ');
		if (!cmd)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		s = get_new_path(path, cmd);
		if (!s)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		if (execve(s, cmd, envp) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		outfile;
	int		pipe_num;
	int		cmd_num;
	int		h_d;
	int		i;
	char 	*line;
	char	**path;
	int		*t;

	if (ac >= 5)
	{
		infile = open(av[1], O_RDONLY);
		outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (infile < 0 || outfile < 0)
		{
			perror("Error");
			exit(0);
		}
		i = 4;
		h_d = h_doc(av);
		printf("h_d %d\n", h_d);
		cmd_num = ac - (h_d + 3);
		pipe_num = cmd_num - 1;
		t = malloc(((sizeof(int) * pipe_num)));
		///////////////////////////////
		line = get_path(envp);
		if (!line)
			return (0);
		path = ft_split(line, ':');
		if (!path)
			return (0);
		printf("cmds %d\n", cmd_num);
		printf("pipes %d\n", pipe_num);
		creat_pipes(t, pipe_num);
		printf("wttt\n");
		///////////////////////////////
		first_child(av, t, cmd_num, infile, path, envp);
		///////////////////////////////
		i = 0;
		while (i < (cmd_num - 2))
		{
			regular_child(av, t, i, path, envp);
			i++;
		}
		///////////////////////////////
		last_child(av, t, cmd_num, outfile, path, envp);
		printf("wttt\n");
	}
	else
		write(2, "Error\n", 6);
	
}