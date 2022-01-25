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

	while (line[i] != NULL)
	{
		if (check_line(line[i]))
			return &(line[i][5]);
		i++;
	}
	return (NULL);
}