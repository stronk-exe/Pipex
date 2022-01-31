#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"  // fork
# include "sys/wait.h" // pid
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"

# include "utils/get_next_line.h"

char	*get_path(char	**line);
int     ft_strlen(const char	*s);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
char	*ft_substr(char	*s, int start, int	len);
#endif