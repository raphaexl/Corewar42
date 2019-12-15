/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:01:46 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:29:12 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	display_inf_nan(t_tab *tab, char *str)
{
	int		update_len;
	int		len;

	update_len = 0;
	len = ft_strlen(str);
	if (DIGIT)
		update_len = DIGIT - len;
	if (SIGN == 0 && str[0] == 'i' && (F_PLUS || F_SPACE))
		update_len--;
	if (!F_NEG)
		display_space_zero(tab, ' ', update_len, 1);
	if (F_SPACE && str[0] == 'i' && !F_PLUS)
		display_space_zero(tab, ' ', 1, 1);
	if (F_PLUS && SIGN == 0 && str[0] == 'i')
		display_space_zero(tab, '+', 1, 1);
	ft_putstr(str);
	if (F_NEG)
		display_space_zero(tab, ' ', update_len, 1);
	RET_LEN += len;
}

void	display_sign(t_tab *tab, int i, char *str)
{
	if (i == 1)
	{
		write(1, "+", 1);
		RET_LEN++;
	}
	if (i == 2 && str[0] != '-')
	{
		write(1, "-", 1);
		RET_LEN++;
	}
}

void	case_mantissa_zero(t_tab *tab)
{
	tab->y = 1;
	init_str_f(tab, "00000000000000000000");
}
