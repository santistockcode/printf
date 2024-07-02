#include "libftprintf.h"

void	ft_putstring_fd(char *str, int fd)
{
	while (*str)
	{
		ft_putchar_fd(*str++, fd);
	}
}
void write_and_count_int(int s, int* i)
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
		write_and_count_int((s / 10), i);
	c = (s % 10) + 48;
	ft_putchar_fd(c, 1);
    *i += 1;
}