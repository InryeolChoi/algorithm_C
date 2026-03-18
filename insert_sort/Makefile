NAME = insert_sort
SRC = insert_sort.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all run clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
