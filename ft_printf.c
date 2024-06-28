#include "libftprintf.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (*s++ != '\0')
		c++;
	return (c);
}

void write_and_count_string(char *s, int* i)
{
    if (s)
		write(1, s, ft_strlen(s));
    *i += ft_strlen(s);
}
int ft_printf(char const *format, ...)
{
    va_list args;
    va_start( args, format);
    int counter;
    const char *here;

    counter = 0;
    while( *format != '\0')
    {
        if( *format == '%')
        {
            format++;
            if(*format == 's')
                {
                    write_and_count_string(va_arg(args, char *), &counter);
                }
        }
        else
        {
            write(1, format, 1);
            counter++;
        }
        format++;
    }
    printf("\ncounter: %d\n", counter);
    va_end(args);
    return 1;
}
int main() {
    // Usage example
    ft_printf("Hello %s, bitch", "world");

    return 0;
}

