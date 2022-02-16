/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:26:07 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 15:53:26 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_exit(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	exit(1);
}

/*
void	ft_freeing(char **path, int *pipes, int infile, int outfile)
{
	int	i;

	i =0;
	close(infile);
	close(outfile);

	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(pipex->cmd);
	free(pipex->pipes);
}
*/