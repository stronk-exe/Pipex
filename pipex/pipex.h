/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:19:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/06 17:29:18 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/wait.h"
#include "stdlib.h"

int	ft_strlen(const char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*get_path(char **line);
char	*get_new_path(char **path, char **cmd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char	*s, int start, int	len);

#endif