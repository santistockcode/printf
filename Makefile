
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

# ******** COLORES ********

GREEN	=	\033[38;5;76m
RED		=	\033[38;5;160m
YELLOW	=	\033[38;5;226m
ORANGE	=	\033[38;5;202m
BLUE	=	\033[38;5;117m
INDI	=	\033[38;5;99m
RESET	=	\033[00m
BLINK   =   \e[5m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@ cp $(LIBFT) $(NAME)
	@ ar rcs $(NAME) $(OBJS)
	@printf "$(YELLOW)$(BLINK)libftprintf.a created$(RESET)\n"

$(OBJS): %.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	@ make -C $(LIBFT_PATH) all

clean:
	@ make -C $(LIBFT_PATH) clean
	@ $(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@ make -C $(LIBFT_PATH) fclean
	@ $(RM) $(NAME)
	@ printf "$(GREEN)Removing libftprintf.a$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re libft