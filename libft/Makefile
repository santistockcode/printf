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

NAME := libft.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar -rc
PATH := objects/
RM := rm -rf
HEADER = libft.h

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

SRC_BONUS := ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
		
OBJ_NAME = $(SRC:%.c=%.o)

OBJ_NAME_BONUS := $(SRC_BONUS:%.c=%.o)

OBJ = $(addprefix $(PATH)/, $(OBJ_NAME))

OBJ_BONUS = $(addprefix $(PATH)/, $(OBJ_NAME_BONUS))

.PHONY: all re clean fclean

all : $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ_BONUS) 

$(PATH)/%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): | $(PATH)

$(OBJ_BONUS): | $(PATH)

$(PATH):
		mkdir -p $(PATH)
		
clean:
	$(RM) objects/ 

fclean:	clean
	$(RM) $(NAME)

re: fclean all
