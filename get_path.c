#include "stdio.h"

int check_line(char *line)
{
	int		i;
	char	*s;

	i = 0;
	s = "PATH";
	while (s[i])
	{
		if (line[i] != s[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_path(char	**line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (check_line(line[i]))
		{
		//	printf("line-%s\n", &line[i][5]);
			return &(line[i][5]);
		}
		i++;
	}
	
	return (NULL);
}