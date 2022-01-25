#include "pipex.h"

/*
void	pipex(char *cmd1, char *cmd2)
{
	int ends[2];
	pid_t parent;
	char *path = "/usr/bin/ls";
	char *avs[] = {"ls", NULL};
	char *env[] = {NULL};

	pipe(ends);

	parent = fork();
	if (parent < 0)
		return (0);
	
	
}

void	child_process(int	*fd)
{
	dup2(fd[0], STDOUT_FILENO);
	close(fd[1]);
	if (execve(path, avs, env) == -1)
	{
		perror("Error");
		exit(0);
	}
}

void	child_process(int	*fd)
{
	dup2(fd[1], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, avs, env) == -1)
	{
		perror("Error");
		exit(0);
	}
}

int	main()
{
	int pid, i=0;

	pid = fork();
	if (pid < 0)
		return (0);
	else if (!pid)
	{
		printf("child %d\n", pid);
		i++;
	}
	else
		printf("parent %d\n", pid);
	printf("i %d\n", i);
}
*/
int main(int ac, char **av, char **envp)
{
	int fd[2];
	int	i = 0;
	int		x = 0;
	char **path;
	char *line, *t1, *t2;
	int pid;

	line = get_path(envp);
	if (!line)
		return (0);
	printf("%s\n", line);
	path = ft_split(line, ':');
	printf("%s\n", path[i]);
	while (path[i])
	{
		t1 = ft_strjoin(path[i], av[2]);
		if (access(t1, X_OK))
		{
		//	free(path);
			x = 1;
			break;
		}
		i++;
	}
	if (!x)
		return (0);
	printf("t1 %s\n", t1);

	i = 0;
	x = 0;
	while (path[i])
	{
		t2 = ft_strjoin(path[i], av[3]);
		printf("t22 %s\n", t2);
		if (!access(t2, X_OK))
		{
			free(path);
			x = 1;
			break;
		}
		i++;
		free(t2);
	}
	if (!x)
		return (0);
	printf("t2 %s\n", t2);
	
	if (ac > 1)
	{
		pipe(fd);
		pid = fork();
		if (pid < 0)
			return (0);


		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd[1], STDIN_FILENO);
			close(fd[1]);
			if (execve(t2, av, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
		else
		{
			wait(0);
			close(fd[1]);
			dup2(fd[0], STDOUT_FILENO);
			close(fd[0]);
			if (execve(t1, av, envp) == -1)
			{
				perror("Error");
				exit(0);
			}
		}
	}
	
}
