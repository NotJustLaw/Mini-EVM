NAME        = mini_evm

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

SRC         = main.c parser/parser.c stack/stack.c evm_loop.c
OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

valgrind: all
	valgrind --leak-check=full ./$(NAME)

valgrind_deep: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re valgrind valgrind_deep