/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:28:06 by saalarco          #+#    #+#             */
/*   Updated: 2024/07/12 19:47:28 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstring_fd(char *str, int fd)
{
	while (*str)
	{
		ft_putchar_fd(*str++, fd);
	}
}

void	ft_putnbr_count(int s, int *i)
{
	char	c;

	if (s == INT_MIN)
	{
		ft_putstring_fd("-2147483648", 1);
		return ;
	}
	else if (s < 0)
	{
		s = -s;
		ft_putchar_fd('-', 1);
	}
	if (s >= 10)
		ft_putnbr_count((s / 10), i);
	c = (s % 10) + 48;
	ft_putchar_fd(c, 1);
	*i += 1;
}
