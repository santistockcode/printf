/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saalarco <saalarco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:49:51 by saalarco          #+#    #+#             */
/*   Updated: 2024/07/12 19:27:25 by saalarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_count(char *s, int *i)
{
    if (!s)
        s = "(null)";
	if (s)
        write(1, s, ft_strlen(s));
	*i += ft_strlen(s);
}
