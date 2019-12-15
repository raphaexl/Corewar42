/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:04:56 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:06:18 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*init(t_tab *tab)
{
	RET_LEN = 0;
	tab->i = 0;
	tab->copy = (char *)tab->format;
	tab->flag = "#0-+ ";
	tab->flag_llh = "lLh";
	tab->flag_cspdiouxxf = "cspdiouxXf";
	tab->k = 0;
	tab->y = 0;
	tab->lr = 0;
	return (tab);
}

t_tab	*re_init(t_tab *tab)
{
	int i;

	i = -1;
	while (++i < 6)
	{
		if (i < 2)
			tab->input_flag_llh[i] = '\0';
		tab->input_flag[i] = '\0';
	}
	CSPDIOUXXF = '\0';
	PRECISION = -1;
	DIGIT = 0;
	I_ZP = 0;
	tab->type_float_return = 0;
	tab->y = 0;
	I_LD = 0;
	tab->k = 0;
	tab->lr = 0;
	BIAS_D = 1023;
	BIAS_LD = 16383;
	UPD_LEN = 0;
	INDEX = 0;
	tab->ind = 0;
	tab->indd = 0;
	return (tab);
}

int		init_function(t_tab *tab)
{
	tab->i++;
	parse_flag(tab);
	parse_digit(tab);
	parse_precision(tab);
	parse_flag_llh(tab);
	parse_flag_cspdiouxxf(tab);
	display(tab);
	return (RET_LEN);
}

t_tab	*display(t_tab *tab)
{
	if (CSPDIOUXXF == 'c')
		display_char(tab);
	else if (CSPDIOUXXF == 's')
		display_string(tab);
	else if (CSPDIOUXXF == 'p')
		display_pointer_hex(tab);
	else if (CSPDIOUXXF == 'd' || CSPDIOUXXF == 'i')
		display_decimal(tab);
	else if (CSPDIOUXXF == 'o')
		display_octal_integer(tab);
	else if (CSPDIOUXXF == 'u')
		display_u_decimal(tab);
	else if (CSPDIOUXXF == 'x' || CSPDIOUXXF == 'X')
		display_hex_integer(tab);
	else if (CSPDIOUXXF == 'f')
		display_float(tab);
	else
		other_display(tab);
	return (tab);
}
