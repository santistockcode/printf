/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:49:33 by saalarco          #+#    #+#             */
/*   Updated: 2024/07/12 19:58:40 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_valid_base(char *str)
{
	size_t	i;
	char	unique;
	size_t	max;
	size_t	position;

	i = 0;
	max = ft_strlen(str);
	if (max == 1)
		return (0);
	while (str[i] != '\0')
	{
		position = i;
		unique = str[i];
		while (i < max)
		{
			i++;
			if (unique == str[i])
				return (0);
		}
		i = position + 1;
		if (unique == '+' || unique == '-' || unique == '%' || unique == '/'
			|| unique == '*' || unique == '=' || unique < 33 || unique > 126)
			return (0);
	}
	return (1);
}

void	put_number(size_t n, char *base, size_t len, int *i)
{
	if (n >= len)
		put_number((n / len), base, len, i);
	ft_putchar_fd(base[(n % len)], 1);
	*i += 1;
}

void	ft_putnbr_hex_count(size_t nbr, char *base, int *i, int pointer)
{
	if (pointer == 1)
	{
		write(1, "0x", 2);
		*i += 2;
	}
	if (is_valid_base(base))
	{
		put_number(nbr, base, ft_strlen(base), i);
	}
}
