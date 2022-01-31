#include "pipex.h"

char	*get_new_path(char **path, char **cmd)
{
	int		i;
	char	*t;

	i = 0;
	while (path[i])
	{
		t = ft_strjoin(path[i], cmd[0]);
		if (!t)
			return (NULL);
		if (!access(t, 0))
		{
			return (t);
		}
		i++;
		free(t);
	}
	return (NULL);
}

int main(int ac, char **av, char **envp)
{
	int fd[2];
	char **path;
	char *line, *t1, *t2;
	pid_t pid;
	pid_t pid2;
	int	infile, outfile;

	char **c1;
	char **c2;

	if (ac == 5)
	{

		infile = open(av[1], O_RDONLY);
		if (infile < 0)
			return (0);
		outfile = open(av[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
		if (outfile < 0)
			return (0);
		
		if (pipe(fd) < 0)
			return (0);
		

		line = get_path(envp);
		if (!line)
			return (0);

		path = ft_split(line, ':');
		if (!path)
			return (0);
		///////////////////  first child ////////////////////////////
		pid = fork();
		
		if (pid < 0)
			return (0);
		if (pid == 0)
		{
			dup2(fd[0], 0);
			close(fd[0]);
			dup2(infile, 0);
		//	close(fd[1]);

			c1 = ft_split(av[2], ' ');
			if (!c1)
				return (0);
			
			t1 = get_new_path(path, c1);
			if (!t1)
				return (0);
			
			if (execve(t1, c1, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}


		///////////////////  second child ////////////////////////////
		pid2 = fork();
		if (pid2 < 0)
			return (0);
		if (pid2 == 0)
		{
			dup2(fd[0], 0);
			close(fd[1]);
			dup2(outfile, 1);
		//	close(fd[1]);

		c2 = ft_split(av[3], ' ');
		if (!c2)
			return (0);
		
		t2 = get_new_path(path, c2);
		if (!t2)
			return (0);
		free(path);
		if (execve(t2, c2, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}


	
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(2, "Error\n", 6);
	// free(t1);
	// free(t2);
	// free(c1);
	// free(c2);
	return (0);
}
