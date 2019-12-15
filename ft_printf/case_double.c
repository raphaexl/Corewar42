/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:27:12 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/10 23:19:49 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_float(t_tab *tab)
{
	char	*str;

	tab->input_float = get_type_float(tab);
	if (check_type(tab) == 0)
		return (tab);
	if (EXPONENT == 0)
		BIAS_D = 1022;
	if (EXPONENT - BIAS_D < 0)
		str = power(tab, 5, -EXPONENT + BIAS_D);
	else if (EXPONENT - BIAS_D > 0)
		str = power(tab, 2, EXPONENT - BIAS_D);
	else
	{
		init_str_f(tab, mantisa_calc(tab));
		free_str(tab->ret, tab->sub, NULL);
		return (tab);
	}
	init_str_f(tab, no_zero(tab, string_multi(tab, str, mantisa_calc(tab))));
	free_string(tab);
	ft_strdel(&str);
	return (tab);
}

char	*mantisa_calc(t_tab *tab)
{
	int	i;
	int len;

	i = 1;
	tab->result = str_zero(52);
	while (MANTISSA)
	{
		if (MANTISSA & 1)
		{
			tab->calc = power(tab, 5, 52 - i + 1);
			tab->calc = join(tab->calc, str_zero(i - 1));
		}
		else
			tab->calc = NULL;
		if (tab->calc != NULL)
			tab->result = string_add(tab, tab->result, tab->calc);
		MANTISSA = MANTISSA >> 1;
		i++;
		ft_strdel(&tab->calc);
	}
	len = ft_strlen(tab->result);
	tab->sub = ft_strsub(tab->result, len - 52, len);
	if (mantissa_calc_2(tab) == 1)
		return (tab->sub);
	return (tab->ret);
}

int		check_type(t_tab *tab)
{
	if (tab->type_float_return == 1)
	{
		display_f_2(tab, tab->nan_inf);
		return (0);
	}
	if (check_inf_nan(tab) != 0)
	{
		display_f_2(tab, tab->nan_inf);
		return (0);
	}
	if (I_LD == 1)
	{
		if (MANTISSA_L == 0 && (I_ZP = 1))
			case_mantissa_zero(tab);
		else
			case_long_double(tab);
		return (0);
	}
	if (!I_LD && MANTISSA == 0 && (I_ZP = 1))
	{
		case_mantissa_zero(tab);
		return (0);
	}
	return (1);
}

int		mantissa_calc_2(t_tab *tab)
{
	if (!EXPONENT)
	{
		tab->indd = 1;
		ft_strdel(&tab->result);
		return (1);
	}
	tab->ret = ft_strjoin("1", tab->sub);
	free_str(tab->result, NULL, NULL);
	return (0);
}

void	free_string(t_tab *tab)
{
	if (tab->ind != 1)
		free(tab->tmp_2);
	if (tab->indd != 1)
		ft_strdel(&tab->ret);
	ft_strdel(&tab->tmp_1);
	ft_strdel(&tab->sub);
}
