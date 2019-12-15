/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_octal_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:30:14 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:30:30 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_octal_integer(t_tab *tab)
{
	char		*str;
	uintmax_t	num;

	num = type_octal_integer(tab);
	if (num == 0 && PRECISION == 0 && F_HASH != '#')
	{
		display_space_zero(tab, ' ', DIGIT, 1);
		return (tab);
	}
	if (!(str = ft_itoa_base(num, 8, 'a')))
		exit(-1);
	if (F_0 == '0' && PRECISION == -1 && F_NEG != '-')
		PRECISION = DIGIT;
	display_o(tab, num, str);
	return (tab);
}

t_tab	*display_o(t_tab *tab, uintmax_t num, char *str)
{
	int		len;
	int		len_str;

	len_str = ft_strlen(str);
	if (F_HASH == '#' && num)
		len_str++;
	len = len_str;
	if (PRECISION > 0 && PRECISION >= len_str)
		len = PRECISION;
	if (DIGIT >= len)
		RET_LEN += DIGIT;
	else
		RET_LEN += len;
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - len, 0);
	if (F_HASH == '#' && num)
		write(1, "0", 1);
	display_space_zero(tab, '0', PRECISION - len_str, 0);
	ft_putstr(str);
	ft_strdel(&str);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - len, 0);
	return (tab);
}
