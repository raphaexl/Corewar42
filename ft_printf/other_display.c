/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:15:19 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:15:30 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*other_display(t_tab *tab)
{
	if (tab->copy[tab->i] == '%')
	{
		display_percent(tab);
		return (tab);
	}
	if (F_0 == '0' && PRECISION <= 0 && !F_NEG)
	{
		PRECISION = DIGIT;
		DIGIT = 0;
	}
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	if (F_0 == '0')
		display_space_zero(tab, '0', PRECISION - 1, 1);
	write(1, &tab->copy[tab->i], 1);
	if (F_HASH == '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	RET_LEN++;
	return (tab);
}

t_tab	*display_percent(t_tab *tab)
{
	if (F_0 == '0' && PRECISION <= 0 && !F_NEG)
	{
		PRECISION = DIGIT;
		DIGIT = 0;
	}
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	if (F_0 == '0')
		display_space_zero(tab, '0', PRECISION - 1, 1);
	write(1, "%", 1);
	if (F_HASH == '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	RET_LEN++;
	return (tab);
}
