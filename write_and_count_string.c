#include "libftprintf.h"

void write_and_count_string(char *s, int* i)
{
    while(s)
    {
        write(1, &s, ft_strlen(s));
        (*i)++;
    }

}