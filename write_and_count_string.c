#include "libftprintf.h"

void write_and_count_string(char *s, int* i)
{
    if (s)
		write(1, s, ft_strlen(s));
    *i += ft_strlen(s);
}