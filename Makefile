NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra
AR := ar -rc
PATH := objects/
RM := rm -rf
HEADER = libftprintf.h
LIBFT = libft
DIR_PRINTF = src/

SRC_NAME := ft_printf.c

SRC += $(addprefix $(DIR_PRINTF), $(FILES_PRINTF))

OBJ_NAME = $(SRC:%.c=%.o)
OBJ = $(addprefix $(PATH)/, $(OBJ_NAME))

.PHONY: all re clean fclean

all: $(NAME)

# $(info OBJ_NAME: $(OBJ_NAME))
# $(info SRC: $(SRC))
# $(info OBJ: $(OBJ))

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ): | $(PATH)

$(PATH)/%.o: %.c $(HEADER) | DIRECTORY
	make -C $(LIBFT)
	cp libft/libft.a .
	mv libft.a $(NAME)
	$(CC) $(CFLAGS) -c $< -o $@

DIRECTORY:
		@mkdir -p $(PATH)

clean:
	$(RM) libft/src/objects
	$(RM) $(PATH)
	@printf "$(GREEN)Removing objects folder$(RESET)\n"

fclean:	clean
	@ $(RM) libft/libft.a
	@ $(RM) $(NAME)
	@printf "$(GREEN)Removing library$(RESET)\n"

re: fclean all	

# 	make fclean -C $(LIBFT)
# 	make clean -C $(LIBFT)


# TESTS_PATH = ./saalarco-tests

#run-tests:
#	@make run-tests -C $(TESTS_PATH)

#fclean:
#	@make fclean -C $(TESTS_PATH)