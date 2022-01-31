NAME = pipex

SRCS = pipex.c pipex_utils.c pipex_utils_1.c get_path.c utils/get_next_line.c utils/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re