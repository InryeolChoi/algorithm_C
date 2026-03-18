NAME = quicksort2
SRC = quicksort2.c
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
