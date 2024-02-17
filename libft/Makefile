# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:51:21 by saalarco          #+#    #+#              #
#    Updated: 2024/02/14 10:11:15 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES GENERALES ********

NAME := libft.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar -rc
PATH := objects/
RM := rm -rf
HEADER = libft.h

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m
BLINK   =   \e[5m

# ******** VARIABLES PARTE OBLIGATORIA ********

SRC := ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_itoa.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c

OBJ_NAME = $(SRC:%.c=%.o)

OBJ = $(addprefix $(PATH)/, $(OBJ_NAME))

# ******** VARIABLES PARTE BONUS ********

SRC_BONUS := ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJ_NAME_BONUS := $(SRC_BONUS:%.c=%.o)

OBJ_BONUS = $(addprefix $(PATH)/, $(OBJ_NAME_BONUS))

# ******** REGLAS ********

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJ)
		@ $(AR) $(NAME) $(OBJ) 
		@printf "$(YELLOW)$(BLINK)libft.a created$(RESET)\n"

$(OBJ): | $(PATH)

$(PATH)/%.o: %.c $(HEADER)
		@ $(CC) $(CFLAGS) -c $< -o $@

# ** reglas para los bonus

bonus: $(OBJ_BONUS)
	@ $(AR) $(NAME) $(OBJ_BONUS)
	@printf "$(BLUE)Bonus$(INDI) into$(ORANGE) libft,$(RED) hurray!$(RESET)\n"

$(OBJ_BONUS): | $(PATH)

# ** crea la carpeta para los objetos

$(PATH):
		@ mkdir -p $(PATH)

# ** CLEAN FCLEAN RE 

clean:
	@ $(RM) objects/ 
	@printf "$(GREEN)Removing objects folder$(RESET)\n"

fclean:	clean
	@ $(RM) $(NAME)
	@printf "$(GREEN)Removing libft.h$(RESET)\n"


re: fclean all


# **************************************************************************** #
# UN MAKEFILE CON PRINTFS SIN COMENTAR NO SE PUEDE ENTREGAR ****************** #
# **************************************************************************** #
