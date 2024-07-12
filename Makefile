# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 18:50:25 by saalarco          #+#    #+#              #
#    Updated: 2024/07/12 18:50:30 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES GENERALES ********

NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT_NAME = $(LIBFT_PATH)/libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar_count.c ft_putnbr_count.c ft_putstr_count.c ft_putnbr_hex_count.c
OBJS = $(SRC:.c=.o)

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m
BLINK   =   \e[5m

# ******** REGLAS ********

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	@ cp $(LIBFT_NAME) $(NAME)
	@ ar rcs $(NAME) $(OBJS)
	@ printf "$(GREEN)libftprintf.a created$(RESET)\n"

# $(OBJS): %.o: %.c
#	@ $(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_PATH)

$(LIBFT_NAME):
	@ make -C $(LIBFT_PATH) all

clean:
	@ make -C $(LIBFT_PATH) clean
	@ $(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@ make -C $(LIBFT_PATH) fclean
	@ $(RM) $(NAME)
	@ printf "$(GREEN)Removing libftprintf.a$(RESET)\n"

re: fclean all

# **************************************************************************** #
# UN MAKEFILE CON PRINTFS y tanto @ NO SE DEB ENTREGAR(TODO)****************** #
# **************************************************************************** #
