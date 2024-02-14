CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = tests_libft.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = ../
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)ft_*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)
HEADER = ../libft.h

.PHONY: all clean fclean re

run-tests: test
	./test

all: test

test: $(OBJS) $(LIBFT_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBFT_OBJS)

fclean: clean
	rm -f test

re: fclean all
