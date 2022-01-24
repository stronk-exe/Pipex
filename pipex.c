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
int main()
{
	int fd[2];
	char *path = "/usr/bin/ls";
	char *avs[] = {"ls", NULL};
	char *env[] = {NULL};
	int pid;

	pipe(fd);
	pid = fork();
	if (pid < 0)
		return (0);


	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDIN_FILENO);
		close(fd[1]);
		if (execve(path, avs, env) == -1)
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
		if (execve(path, avs, env) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
}
