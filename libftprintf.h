
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int ft_printf(char const *str, ...);
void write_and_count_string(char *s, int* i);
void write_and_count_int(int s, int* i);

#endif