#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	c;

// 	c = 0;
// 	while (*s++ != '\0')
// 		c++;
// 	return (c);
// }

// void write_and_count_string(char *s, int* i)
// {
//     if (s)
// 		write(1, s, ft_strlen(s));
//     *i += ft_strlen(s);
// }
int ft_printf(char const *format, ...) {
  va_list args;
  va_start(args, format);
  int printedCount;
  char c;

    printedCount = 0;
    while (*format) {
        if (*format == '%') {
        format++;
            if (*format == 's') {
                ft_putstr_count(va_arg(args, char *), &printedCount);
            }
            if (*format == 'd') {
                ft_putnbr_count(va_arg(args, int), &printedCount);
            }
            if (*format == 'c') {
                c = (char) va_arg(args, int);
                ft_putchar_count(c, &printedCount);
            }
            if (*format == '%') {
                write(1, "%", 1);
                printedCount += 1;
            }
            if (*format == 'x') {
                //ft_putnbr_hex_count((size_t) va_arg(args, void *), &printedCount);
                write(1, "0x", 2);
                printedCount+=2;
                ft_putnbr_hex_count(va_arg(args, int), "0123456789abcdef", &printedCount);
            }
            if (*format == 'X') {
                write(1, "0x", 2);
                printedCount+=2;
                ft_putnbr_hex_count(va_arg(args, int), "0123456789ABCDEF", &printedCount);
            }
            if (*format == 'p') {
                write(1, "0x", 2);
                printedCount+=2;
                ft_putnbr_hex_count((size_t) va_arg(args, void*), "0123456789abcdef", &printedCount);
            }
        } 
        else {
            ft_putchar_count(*format, &printedCount);
        }
        format++;
  }
  va_end(args);

  return printedCount;
}
// int main() {
//     // Usage example
//     ft_printf("Hello %s, bitch", "world");

//     return 0;
// }
