/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:37:01 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 12:10:29 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 3
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../../pipex.h"

char	*ft_strjoin2(char *s1, char *s2);
int		ft_strchr(char	*s);
size_t	ft_strle(const char	*s);
char	*ft_substr2(char	*s, unsigned int start, size_t	len);
size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize);
char	*ft_strdup2(char *s1);
char	*get_next_line(int fd);

#endif