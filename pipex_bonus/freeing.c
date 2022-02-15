/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:26:07 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/15 15:35:58 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
//	free(cmd);
	free(pipes);
}