/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_hex_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:29:41 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:29:46 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_hex_integer(t_tab *tab)
{
	char		*str;
	char		c;
	uintmax_t	num;
	int			index;

	index = 0;
	num = type_hex_integer(tab);
	if (num == 0 && PRECISION == 0)
	{
		display_space_zero(tab, ' ', DIGIT, 1);
		return (tab);
	}
	c = 'a';
	if (CSPDIOUXXF == 'X')
		c = 'A';
	if (!(str = ft_itoa_base(num, 16, c)))
		exit(-1);
	if (F_0 == '0' && PRECISION == -1 && !F_NEG)
	{
		index = 1;
		PRECISION = DIGIT;
	}
	display_x(tab, num, str, index);
	ft_strdel(&str);
	return (tab);
}

t_tab	*display_x(t_tab *tab, uintmax_t num, char *str, int index)
{
	ZERO = 0;
	CALC_2 = 0;
	LEN_STR = ft_strlen(str);
	if ((PRECISION > 0) && (PRECISION > LEN_STR) && index == 0)
		ZERO = PRECISION - LEN_STR;
	if (F_HASH == '#' && num && F_0 == '0' && DIGIT > 1)
		LEN_STR += 2;
	else if (F_HASH == '#' && num)
	{
		DIGIT -= 2;
		RET_LEN += 2;
	}
	LEN = (PRECISION >= LEN_STR && PRECISION > 0) ? PRECISION : LEN_STR;
	RET_LEN += (DIGIT >= LEN) ? DIGIT : LEN;
	CALC = PRECISION - LEN_STR;
	CALC_2 = DIGIT - LEN;
	if (ZERO)
		CALC_2 = (DIGIT) - (ZERO + LEN_STR);
	if (!ZERO)
		ZERO = CALC;
	display_x_2(tab, num, str);
	return (tab);
}

void	display_x_2(t_tab *tab, uintmax_t num, char *str)
{
	if (F_NEG != '-')
		display_space_zero(tab, ' ', CALC_2, 0);
	display_0x(num, F_HASH, CSPDIOUXXF);
	display_space_zero(tab, '0', ZERO, 0);
	ft_putstr(str);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - LEN, 0);
}
