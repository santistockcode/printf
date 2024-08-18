/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:47:51 by saalarco          #+#    #+#             */
/*   Updated: 2024/08/04 22:02:20 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

int	switch_format_specifier(va_list args, char const *format, int p_count)
{
	size_t	pointer;

	if (*format == 's')
		ft_putstr_count(va_arg(args, char *), &p_count);
	if (*format == 'd' || *format == 'i')
		ft_putnbr_count(va_arg(args, int), &p_count);
	if (*format == 'c')
		ft_putchar_count((char)va_arg(args, int), &p_count);
	if (*format == '%')
		ft_putchar_count('%', &p_count);
	if (*format == 'x')
		ft_putnbr_hex_count(va_arg(args, unsigned int), HEX_L, &p_count, 0);
	if (*format == 'X')
		ft_putnbr_hex_count(va_arg(args, unsigned int), HEX_U, &p_count, 0);
	if (*format == 'p')
	{
		pointer = (size_t)va_arg(args, void *);
		ft_putnbr_hex_count(pointer, HEX_L, &p_count, 1);
	}
	if (*format == 'u')
		ft_putnbr_hex_count(va_arg(args, unsigned int), DEC, &p_count, 0);
	return (p_count);
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
