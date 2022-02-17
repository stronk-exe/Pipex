# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 19:33:58 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/17 14:50:54 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

BONUS = pipex_b

SRCS = pipex.c\
		get_path.c\
		pipex_utils.c\
		pipex_utils2.c\
		childs.c\
		throw_error.c\
		freeing.c

CSRCS = pipex_bonus/pipex_bonus.c\
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

COBJS = $(CSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) $^ -o $@
		
bonus : $(BONUS)

$(BONUS): $(COBJS)
		cc $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(COBJS)

fclean: clean
		rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus