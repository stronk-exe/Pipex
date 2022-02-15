/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 21:18:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/15 16:11:53 by ael-asri         ###   ########.fr       */
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
/*
void	creat_pipes(int *t, int n)
{
	int	i;

	i = 0;
//	printf("n %d\n", n);
	while (i < n)
	{
		if (pipe((t + 2 * i)) < 0)
			exit(1);
	//	for(int k=0;k<n;k++)
	//		printf("t[%d] %d\n", k, t[k]);
		i++;
	}
}

void	first_child(char **av, int infile, char **path, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;
	int		i;
	int		fd[2];

	i = 0;
	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	if (pid == 0)
	{
	//	printf("av %s\n", av[2]);
		dup2(fd[1], 1);
		dup2(infile, 0);
		close(fd[0]);
	//	printf("s %s\n", av[2]);
	//	close(t[i]);
		///////////////////////////////
		printf("hiiiii im in \n");
		printf("av %s\n", av[2]);
		cmd = ft_split(av[2], ' ');
		if (!cmd)
		{
			perror("Error");
			exit(0);
		}
		///////////////////////////////
		s = get_new_path(path, cmd);
	//	printf("s %s\n", av[2]);
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
//	return (fd[0]);
//	printf("----------first child\n");
}

void	last_child(char **av, int n, int outfile, char **path,char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;
	int		i;
	int		fd[2];

	i = 0;
	if (pipe(fd) < 0)
		exit(1);
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		dup2(fd[0], 0);
		dup2(outfile, 1);
	//	close(fd[1]);
		///////////////////////////////
		printf("hiiiii im in \n");
		printf("last av %s\n", av[n+1]);
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
//	printf("---------last child\n");
}

void	regular_child(char **av, int i, char **path, char **envp)
{
	pid_t	pid;
	char	**cmd;
	char	*s;
	int		fd[2];

//	dup2(fd0, 0);
	pipe(fd);
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		exit(0);
	}
	else if (pid == 0)
	{
		dup2(fd[1], 1);
		dup2(fd[0], 0);
		///////////////////////////////
		close(fd[0]);
		close(fd[1]);
		///////////////////////////////
		printf("hiiiii im in \n");
		cmd = ft_split(av[i + 3], ' ');
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
//	return (fd[0]);
}
*/
void	close_pipes(int *pipes, int pipe_num)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		close(pipes[i]);
		i++;
	}
}

void	creat_pipes(int *pipes, int cmd_num, char **path, int infile, int outfile)
{
	int	i;

	i = 0;
	while (i < (cmd_num - 1))
	{
		if (pipe(&pipes[2 * i]) < 0)
			ft_freeing(path, pipes, infile, outfile);
		//	exit(1);
		i++;
	}
}

void	create_child(char **av, int index, int cmd_num, int *pipes, int infile, int outfile, char **path, char **envp, int pipe_num)
{
	int		pid;
	char	**cmd;
	char	*argv;
printf("hiii\n");
//printf("index %d\n", index);
	//		printf("av index %d\n", *pipes[2 * index - 2]);
	pid = fork();
	if (!pid)
	{
		
		if (index == 0)
		{
		//	printf("av index %d\n", infile);
			dup2(infile, 0);
		//	printf("av index %d\n", pipes[1]);
			dup2(pipes[1], 1);
		}
		else if (index == (cmd_num - 1))
		{
			dup2(pipes[2 * index - 2], 0);
		//	printf("av index %d\n", pipes[2 * index - 2]);
			dup2(outfile, 1);
		//	printf("av index %d\n", outfile);
		}
		else
		{
			dup2(pipes[2 * index - 2], 0);
		//	printf("av index %d\n", pipes[2 * index - 2]);
			dup2(pipes[2 * index + 1], 1);
		//	printf("av index %d\n", pipes[2 * index + 1]);
		}
		close_pipes(pipes, pipe_num);
		cmd = ft_split(av[index + 2], ' ');
		if (!cmd)
			exit(1);
		argv = get_new_path(path, cmd);
		if (!argv)
			exit(1);
		execve(argv, cmd, envp);
	}
	
}

int	main(int ac, char **av, char **envp)
{
	int		infile;
	int		outfile;
	int		pipe_num;
	int		cmd_num;
//	int		i;
	char 	*line;
	char	**path;
//	char	*pids;
//	int		**fd;
	int		*pipes;
	int		index;
	
	if (ac >= 5)
	{
	//	check_here_doc();
		line = get_path(envp);
		if (!line)
			return (0);
		path = ft_split(line, ':');
		if (!path)
			return (0);
		infile = open(av[1], O_RDONLY);
		outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0000644);
		if (infile < 0 || outfile < 0)
		{
			perror("Error");
			exit(1);
		}
		cmd_num = ac - (3);
		pipe_num = 2 * (cmd_num - 1);
		pipes = malloc(sizeof(int) * pipe_num);
		if (!pipes)
			return (0);
		creat_pipes(pipes, cmd_num, path, infile, outfile);
		// for (int h=0; h < 8;h++)
		// 	printf("pipes %d\n", pipes[h]);
		index = 0;
		while (index < cmd_num)
		{
			create_child(av, index, cmd_num, pipes, infile, outfile, path, envp, pipe_num);
			index++;
		}
		close_pipes(pipes, pipe_num);
		waitpid(-1, NULL, 0);
	//	ft_freeing(path, pipes, infile, outfile);
		return (0);
	
	


	
	
	/*	pids = malloc(sizeof(int) * cmd_num);
		fd = malloc(sizeof(int) * (cmd_num + 1) * 2);
		if (!pids || !fd)
			return (0);
		///////////////////////////////
		line = get_path(envp);
		if (!line)
			return (0);
		path = ft_split(line, ':');
		if (!path)
			return (0);
	//	printf("cmds %d\n", cmd_num);
	//	printf("pipes %d\n", pipe_num);
	//	creat_pipes(t, pipe_num);
		///////////////////////////////
		first_child(av, infile, path, envp);
	//	int fdout;
	//	int	fd0;
		///////////////////////////////
		i = 3;
		while (i < (cmd_num - 1))
		{
		//	regular_child(av, i, path, envp);
			pids[i] = fork();
			if (pids[i] < 0)
				return (0);
			else if (!pids[i])
			{
				///// child process
				dup2(fd[1], 1);
				dup2(fd[0], 0);
				///////////////////////////////
		//		close(fd[0]);
		//		close(fd[1]);
				///////////////////////////////
				printf("hiiiii im in \n");
				cmd = ft_split(av[i + 3], ' ');
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
				close(fd[i][0]);
				close(fd[i + 1][1]);
			}
			i++;
		}
		/// main process
		
		///////////////////////////////
		last_child(av, cmd_num, outfile, path, envp);
	//	waitid();*/
	}
	else
		write(2, "Error\n", 6);
}