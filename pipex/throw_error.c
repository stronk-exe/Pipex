/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:39:20 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/17 14:57:47 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_error(char *s)
{
	ft_putstr_err("command not found: ");
	ft_putstr_err(s);
	write(2, "\n", 1);
	exit(1);
}

void	main_error(void)
{
	ft_putstr_err("invalid number of arguments\n");
	exit(1);
}

void	malloc_error(void)
{
	ft_putstr_err("malloc error\n");
	exit(1);
}

void	path_error(void)
{
	ft_putstr_err("path error\n");
	exit(1);
}

void	throw_unlink(void)
{
	unlink(".temp");
	write(2, "Error\n", 6);
	exit(1);
}
