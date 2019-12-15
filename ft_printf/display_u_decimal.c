/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:32:46 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:33:14 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_u_decimal(t_tab *tab)
{
	uintmax_t	num;
	int			len;

	num = type_u_decimal(tab);
	if (num == 0 && PRECISION == 0)
	{
		display_space_zero(tab, ' ', DIGIT, 1);
		return (tab);
	}
	len = strlen_digit_u(num);
	if (F_0 == '0' && PRECISION == -1 && F_NEG != '-')
		PRECISION = DIGIT;
	display_u(tab, num, len);
	return (tab);
}

t_tab	*display_u(t_tab *tab, uintmax_t num, int len)
{
	int		update_len;

	update_len = len;
	if (PRECISION >= len)
		update_len = PRECISION;
	RET_LEN += (DIGIT >= update_len) ? DIGIT : update_len;
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - update_len, 0);
	display_space_zero(tab, '0', PRECISION - len, 0);
	ft_putnbrumax(num);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - update_len, 0);
	return (tab);
}

int		strlen_digit_u(uintmax_t num)
{
	int		len;

	len = 1;
	while ((num /= 10) > 0)
		len++;
	return (len);
}
