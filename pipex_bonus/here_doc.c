/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:53 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/15 21:23:46 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pipex.h"
#include "gnl/get_next_line.h"

void	do_smthing(char *s, int temp)
{
	write(temp, s, ft_strlen(s));
	write(temp, "\n", 1);
}

void	put_here(int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		write(1, "pipe ", 5);
		i++;
	}
	write(1, "heredoc> ", 9);
}

int	check_it(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int check_here_doc(int ac, char **av)
{
	char	*s;
	char	*limiter;
	int		infile;
	int		temp;

	temp = open(".temp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (temp < 0)
		exit(1);
	ac++;
	limiter = av[2];
	//	printf("limiter is %s$\n", limiter);
	put_here(ac - 6);
	s = get_next_line(0);
	while (s)
	{
		if (check_it(s, limiter))
			break ;
		put_here(ac - 6);
		do_smthing(s, temp);
		s = get_next_line(0);
	}
	free(s);
	close(temp);
	infile = open(".temp", O_RDONLY);
	if (infile < 0)
		exit(1);
	return (infile);
//	return (0);
}
