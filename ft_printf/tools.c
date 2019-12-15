/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:18:20 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:19:13 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		strlen_digit(intmax_t num)
{
	int		len;

	if (num == -9223372036854775807 - 1)
		return (19);
	if (num < 0)
		num *= -1;
	len = 1;
	while ((num /= 10) > 0)
		len++;
	return (len);
}

void	display_0x(uintmax_t num, char hash, char x)
{
	if (num)
	{
		if (hash == '#' && x == 'x')
			write(1, "0x", 2);
		if (hash == '#' && x == 'X')
			write(1, "0X", 2);
	}
}

void	display_space_zero(t_tab *tab, char c, int len, int update_len)
{
	char	*str;

	if (len > 0)
	{
		if (update_len)
			RET_LEN += len;
		if (!(str = ft_strnew(len)))
			exit(-1);
		ft_memset(str, c, len);
		write(1, str, len);
		ft_strdel(&str);
	}
}

void	ft_putnbrmax(intmax_t n)
{
	if (n == -9223372036854775807 - 1)
		write(1, "-9223372036854775808", 20);
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putnbrumax(uintmax_t n)
{
	if (n > 9)
		ft_putnbrumax(n / 10);
	ft_putchar((n % 10) + '0');
}
