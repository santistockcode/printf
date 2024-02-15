# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saalarco <saalarco@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 12:51:21 by saalarco          #+#    #+#              #
#    Updated: 2024/02/15 16:21:29 by saalarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** LIBFT PARA PRINTF SIN BONUS ********

 
# ******** VARIABLES GENERALES ********

NAME		=	libft.a
CC 			=	cc
CFLAGS 		=	-Wall -Werror -Wextra
AR 			=	ar -rc
OBJTS_DIR 	=	src/objects/
RM 			=	rm -rf
HEADER 		= 	src/libft.h
SRCS_DIR 	=	src/

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

SRC_NAME := ft_isalpha.c \
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

OBJ			=	$(addprefix $(OBJTS_DIR)/, $(OBJ_NAME))
SRC 		=	$(addprefix $(SRCS_DIR)/, $(SRC_NAME))
OBJ_NAME 	=	$(SRC_NAME:%.c=%.o)

# ******** REGLAS ********

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJ)| $(OBJTS_DIR)
		@ $(AR) $(NAME) $(OBJ) 
		@printf "$(YELLOW)$(BLINK)Libft has been been created$(RESET)\n"

# $(info SRC_NAME: $(SRC_NAME))
# $(info OBJ_NAME: $(OBJ_NAME))
# $(info SRC: $(SRC))
# $(info OBJ: $(OBJ))

$(OBJTS_DIR)%.o: $(SRCS_DIR)*.c $(HEADER) | $(OBJTS_DIR)
	 @ $(CC) $(CFLAGS) -c $< -o $@

# ** crea la carpeta para los objetos

$(OBJ): | $(OBJTS_DIR)

$(OBJTS_DIR):
	@ mkdir -p $(OBJTS_DIR)/

# ** CLEAN FCLEAN RE 

clean:
	@ $(RM) $(OBJTS_DIR)
	@printf "$(GREEN)Removing objects folder$(RESET)\n"

fclean:	clean
	@ $(RM) $(NAME)
	@printf "$(GREEN)Removing libft.h$(RESET)\n"


re: fclean all
