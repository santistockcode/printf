#include "libftprintf.h"

int ft_printf(char const *s, ...)
{
    if(s)
        write(1, s, ft_strlen(s));
    return 1;
}

// lo importante es el casteo, que falle en este punto es 
// función que haga el casteo de un argumento a muchos

/*

#include <stdio.h>
#include <stdarg.h>

// Function to print formatted output
int print_formatted(char const *format, ...) {
    va_list args;
    int ret;

    // Initialize va_list
    va_start(args, format);

    // Call vprintf to handle variable arguments
    ret = vprintf(format, args);

    // Cleanup va_list
    va_end(args);

    return ret;
}

int main() {
    // Usage example
    print_formatted("Integer: %d, Float: %f, String: %s\n", 10, 3.14, "Hello");

    return 0;
}

*/

/*
#include <stdio.h>
#include <stdarg.h>

// Variadic function to print characters
void print_chars(char first_char, ...) {
    // Access variable arguments using va_list
    va_list args;
    va_start(args, first_char);

    // Print the first character
    putchar(first_char);

    // Iterate through the variable arguments
    char next_char;
    while ((next_char = va_arg(args, int)) != '\0') {
        putchar(next_char);
    }

    // Cleanup va_list
    va_end(args);
}

int main() {
    // Call the variadic function with characters
    print_chars('H', 'e', 'l', 'l', 'o', '\n');

    return 0;
}

*/