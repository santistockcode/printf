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

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -fsanitize=address
endif

OBJDIR = objs/

VERBOSE ?= 0
ifeq ($(VERBOSE), 1)
    SILENT =
else
    SILENT = @
endif


SRC = ft_printf.c ft_putchar_count.c ft_putnbr_count.c ft_putstr_count.c ft_putnbr_hex_count.c


OBJS = $(SRC:%.c=$(OBJDIR)%.o)

$(OBJDIR)%.o: %.c
	$(SILENT)mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
RESET	=	\033[00m

# ******** REGLAS ********

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(SILENT)cp $(LIBFT_NAME) $(NAME)
	$(SILENT)ar rcs $(NAME) $(OBJS)
	$(SILENT)printf "$(GREEN)libftprintf.a created$(RESET)\n"



$(LIBFT_NAME):
	$(SILENT)$(MAKE) -C $(LIBFT_PATH) all


clean:
	$(SILENT) make -C $(LIBFT_PATH) clean
	$(SILENT)$(RM) $(OBJS)

fclean: clean
	$(SILENT) make -C $(LIBFT_PATH) fclean
	$(SILENT) $(RM) $(NAME)
	$(SILENT)$(RM) -r $(OBJDIR)
	$(SILENT) printf "$(GREEN)Removing libftprintf.a$(RESET)\n"

re: fclean all

