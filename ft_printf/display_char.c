/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:55:33 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/04 15:55:46 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_char(t_tab *tab)
{
	int	c;

	if (ft_strcmp(tab->input_flag_llh, "l") == 0)
		c = (unsigned long)va_arg(tab->args, unsigned long);
	else
		c = (char)va_arg(tab->args, int);
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	RET_LEN++;
	ft_putchar(c);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - 1, 1);
	return (tab);
}
