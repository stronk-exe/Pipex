/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:29:53 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/14 15:41:44 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../pipex.h"
#include "gnl/get_next_line.h"

int check_here_doc(char **av)
{
	char	*s;
	char	*limiter;
	if (ft_strncmp(av[1], "here_doc", 8)
	{
		limiter = av[2];
		s = get_next_line(0);
		while (ft_strncmp(s, limiter, ft_strlen(limiter)))
		{
			do_smthing();
			s = get_next_line(0);
		}
		return (1);
	}
	return (0);
}