#include "libftprintf.h"

void ft_putchar_count(char c, int* i)
{
    write(1, &c, 1);    
    *i += 1;
}
