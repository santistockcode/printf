#include "libftprintf.h"

void ft_putstr_count(char *s, int* i)
{
    if (s)
		write(1, s, ft_strlen(s));
    *i += ft_strlen(s);
}
