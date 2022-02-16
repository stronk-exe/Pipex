# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:33:58 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/16 15:01:51 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BNAME = bonus

SRCS = pipex.c get_path.c pipex_utils.c pipex_utils2.c childs.c throw_error.c freeing.c

BSRCS = pipex_bonus/pipex_bonus.c\
		pipex_bonus/pipex_utils_bonus.c\
		pipex_bonus/here_doc.c\
		pipex_bonus/gnl/get_next_line.c\
		pipex_bonus/gnl/get_next_line_utils.c\
		get_path.c\
		pipex_utils.c\
		pipex_utils2.c\
		throw_error.c\
		freeing.c

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(BNAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) $^ -o $@

$(BNAME) : $(BOBJS)
	cc $(CFLAGS) $^ -o $@

clean : 
	rm -f $(OBJS) $(BOBJS)

fclean : clean
	rm -f $(NAME) $(BNAME)

re : fclean all

.PHONY : all clean fclean bonus re