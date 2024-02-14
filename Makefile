CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = test-main.c


NAME	=	libftprintf.a
OBJS = $(SRCS:.c=.o)
PRINTF_SRCS = $(wildcard ft_*.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
HEADER = libftprintf.h

LIBFT_PATH	= ./libft
LIBFT_NAME	= ./libft/libft.a


GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
PURPLE	=	\033[38;5;213m
LBLUE	=	\033[38;5;51m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m


.PHONY: all clean fclean re

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@make -C $(LIBFT_PATH)

run-tests: test
	./test

test: $(OBJS) $(PRINTF_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PRINTF_OBJS)

fclean: clean
	rm -f test

re: fclean all