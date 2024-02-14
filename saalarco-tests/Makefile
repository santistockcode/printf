# ******** VARIABLES GENERALES ********

CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = $(PARENT_DIR)libftprintf.h

# ******** Variables del printf ********

PARENT_DIR = ../
PRINTF_SRCS = $(wildcard $(PARENT_DIR)*.c)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

# ******** Variables para tests ********

TESTS_SRC = test-main.c
TESTS_OBJ = $(TESTS_SRC:.c=.o)

# ******** Libft ********

LIBFT_NAME	= ./../libft/libft.a

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
PURPLE	=	\033[38;5;213m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m
BLINK   =   \e[5m


.PHONY: all clean fclean re

run-tests: test
	./test

test: $(PRINTF_OBJS) $(TESTS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PRINTF_OBJS) $(TESTS_OBJ)

fclean: clean
	rm -f test

re: fclean all

# ME QUEDO EN QUE 
## no está desacoplado (que primero mande un make a libft, luego mande un make a 
## printf y luego mande un make a run tests 
## y que se creen las cosas en la carpeta OBJECTS y no ahí en medio