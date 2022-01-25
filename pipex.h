#ifndef PIPEX_H
# define PIPEX_H

# include "unistd.h"  // fork
# include "sys/wait.h" // pid
#include "stdlib.h"

#include "stdio.h"

# include "utils/get_next_line.h"

char	*get_path(char	**line);

char	**ft_split(char *s, char c);
char	*ft_substr(char	*s, unsigned int start, size_t	len);
#endif