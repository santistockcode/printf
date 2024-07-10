
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int ft_printf(char const *str, ...);
void ft_putstr_count(char *s, int* i);
void ft_putnbr_count(int s, int* i);
void ft_putchar_count(char c, int* i);
void	ft_putnbr_hex_count(size_t nbr, char *base, int* i);

#endif
