SRC =       ./Sources/*.c

NAME =      My_bc

CC =        gcc -g

RM =        rm -f

CFLAGS =    -O2 -W -Wall -Wextra -Werror

all:$(NAME)

$(NAME):

		$(CC) -o $(NAME) $(SRC)
clean:
		$(RM)
fclean:clean
		$(RM) $(NAME)
re:fclean all

.PHONY:all clean fclean re
