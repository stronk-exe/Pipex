# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:33:58 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/11 15:39:47 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BNAME = bonus

SRCS = pipex.c get_path.c pipex_utils.c pipex_utils2.c

BSRCS = pipex_bonus/pipex_bonus.c\
		get_path.c\
		pipex_utils.c\
		pipex_utils2.c

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