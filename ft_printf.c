/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:47:51 by saalarco          #+#    #+#             */
/*   Updated: 2024/07/12 19:56:26 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	switch_format_specifier(va_list args, char const *format, int printed_count)
{
	if (*format == 's')
	{
		ft_putstr_count(va_arg(args, char *), &printed_count);
	}
	if (*format == 'd')
	{
		ft_putnbr_count(va_arg(args, int), &printed_count);
	}
	if (*format == 'c')
	{
		ft_putchar_count((char)va_arg(args, int), &printed_count);
	}
	if (*format == '%')
	{
		ft_putchar_count('%', &printed_count);
	}
	if (*format == 'x')
	{
		ft_putnbr_hex_count(va_arg(args, int), "0123456789abcdef", &printed_count, 0);
	}
	if (*format == 'X')
	{
		ft_putnbr_hex_count(va_arg(args, int), "0123456789ABCDEF", &printed_count, 0);
	}
	if (*format == 'p')
	{
		ft_putnbr_hex_count((size_t)va_arg(args, void *), "0123456789abcdef", &printed_count, 1);
	}
	return (printed_count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		printed_count;

	va_start(args, format);
	printed_count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			printed_count = switch_format_specifier(args, format,
					printed_count);
		}
		else
		{
			ft_putchar_count(*format, &printed_count);
		}
		format++;
	}
	va_end(args);
	return (printed_count);
}
// int main() {
//     // Usage example
//     ft_printf("Hello %s, bitch", "world");

//     return (0);
// }
