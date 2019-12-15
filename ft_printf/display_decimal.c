/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:56:00 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/04 15:58:49 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_decimal(t_tab *tab)
{
	intmax_t	num;
	int			len;

	num = type_decimal(tab);
	if (num == 0 && PRECISION == 0)
	{
		display_decimal_2(tab);
		return (tab);
	}
	len = strlen_digit(num);
	if (F_0 == '0' && PRECISION == -1 && F_NEG != '-')
	{
		PRECISION = DIGIT;
		if (num < 0 || F_SPACE == ' ' || F_PLUS == '+')
			PRECISION--;
	}
	display_d(tab, num, len);
	return (tab);
}

t_tab	*display_d(t_tab *tab, intmax_t num, int len)
{
	int		update_len;
	int		is_sign;
	char	display_input_flag;

	update_len = len;
	is_sign = (num < 0) ? 1 : 0;
	num *= (is_sign && num != (-MAX_L - 1)) ? -1 : 1;
	display_input_flag = get_input_flag(tab, is_sign);
	if (PRECISION >= len && PRECISION >= 0)
		update_len = PRECISION;
	if (display_input_flag)
		update_len++;
	RET_LEN += (DIGIT >= update_len) ? DIGIT : update_len;
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - update_len, 0);
	if (display_input_flag)
		write(1, &display_input_flag, 1);
	display_space_zero(tab, '0', PRECISION - len, 0);
	if (num != (-MAX_L - 1))
		ft_putnbrmax(num);
	else if (RET_LEN > 0)
		write(1, "9223372036854775808", 19);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - update_len, 0);
	return (tab);
}

char	get_input_flag(t_tab *tab, int is_sign)
{
	if (is_sign)
		return ('-');
	if (F_PLUS == '+')
		return ('+');
	if (F_SPACE == ' ')
		return (' ');
	return ('\0');
}

void	display_decimal_2(t_tab *tab)
{
	if (DIGIT == 0 && F_SPACE == ' ')
		DIGIT = 1;
	if (F_PLUS == '+')
	{
		RET_LEN++;
		if (F_NEG == '-')
			write(1, "+", 1);
		display_space_zero(tab, ' ', DIGIT - 1, 1);
		if (F_NEG != '-')
			write(1, "+", 1);
	}
	else if (F_SPACE == ' ')
		display_space_zero(tab, ' ', DIGIT, 1);
	else
		display_space_zero(tab, ' ', DIGIT, 1);
}
