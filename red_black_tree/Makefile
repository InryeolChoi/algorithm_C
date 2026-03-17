CC := cc
CFLAGS := -Wall -Wextra -Werror -std=c11
TARGET := red_black_tree

SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
HEADERS := $(wildcard *.h)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
