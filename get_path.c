/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:18:56 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/06 17:42:19 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_line(char	*s)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_strdup("PATH");
	while (p[i])
	{
		if (s[i] != p[i])
			return (0);
		i++;
	}
	return (1);
	
}
char	*get_path(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL)
	{
		if (check_line(line[i]))
			return &(line[i][5]);
		i++;
	}
	return (NULL);
}

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
			return (t);
		i++;
		free(t);
	}
	return (NULL);
}