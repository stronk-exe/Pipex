/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:19:10 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/16 18:33:39 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "stdio.h"
# include "unistd.h"
# include "fcntl.h"
# include "sys/wait.h"
# include "stdlib.h"

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	int		pipe_num;
	int		cmd_num;
	char	**path;
	int		*pipes;
	int		index;
	int		is_here_doc;	
}	t_pipe;

///// -------------childs
int		first_child(char **av, int *fd, char **path, char **envp);
int		second_child(char **av, int *fd, char **path, char **envp);

///// -------------errors
void	throw_error(void);
void	free_and_error(char **s);
void	throw_unlink(void);

///// -------------freeing
void	free_and_exit(char **s);

///// -------------utils
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*get_line(char **envp);
char	**get_path(char **envp);
char	*get_new_path(char **path, char **cmd);
char	*ft_strdup(const char *s1);
char	*ft_substr(char	*s, int start, int len);

///// -------------bonus
void	creat_pipes(t_pipe *pipex);
void	close_pipes(t_pipe *pipex);
void	create_child(char **av, t_pipe *pipex, char **envp);
int		ft_exec(char **av, t_pipe *pipex, char **envp);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_freeing(char **path, int *pipes, int infile, int outfile);
int		check_here_doc(char **av);

#endif