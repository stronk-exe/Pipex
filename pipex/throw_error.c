/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:20 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 17:59:23 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	throw_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_and_error(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	throw_error();
}

void	throw_unlink(void)
{
	unlink(".temp");
	write(2, "Error\n", 6);
	exit(1);
}
