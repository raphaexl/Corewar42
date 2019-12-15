/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:11:50 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:14:12 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*string_multi(t_tab *tab, char *s1, char *s2)
{
	char	*calc;

	I = -1;
	tab->tmp_1 = str_zero(ft_strlen(s1) + ft_strlen(s2));
	while (s2[++I] != '\0')
	{
		calc = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		RET = 0;
		I_CALC = 0;
		J = ft_strlen(s1);
		while (--J >= 0)
		{
			K = (((s2[I] - 48) * (s1[J] - 48))) + RET;
			calc[I_CALC++] = ((K) % 10) + 48;
			RET = K / 10;
		}
		if (RET != 0)
			calc[I_CALC++] = RET + 48;
		calc[I_CALC] = '\0';
		calc = join(ft_strrev(calc), str_zero(ft_strlen(s2) - I - 1));
		tab->tmp_1 = string_add(tab, tab->tmp_1, calc);
		ft_strdel(&calc);
	}
	return (tab->tmp_1);
}

char	*string_add(t_tab *tab, char *s1, char *s2)
{
	K_ADD = 0;
	I_ADD = ft_strlen(s1);
	J_ADD = ft_strlen(s2);
	STR_ADD = ft_strnew(I_ADD + 2);
	STR_ADD[I_ADD + 1] = '\0';
	I_ADD--;
	while (--J_ADD >= 0)
	{
		K_ADD = K_ADD + s1[I_ADD] + s2[J_ADD] - 48 * 2;
		if (K_ADD < 10)
		{
			STR_ADD[I_ADD + 1] = K_ADD + '0';
			K_ADD = 0;
		}
		else
		{
			STR_ADD[I_ADD + 1] = K_ADD + '0' - 10;
			K_ADD = 1;
		}
		I_ADD--;
	}
	string_add_2(tab, s1);
	ft_strdel(&s1);
	return (STR_ADD);
}

void	string_add_2(t_tab *tab, char *s1)
{
	while (I_ADD >= 0)
	{
		K_ADD = K_ADD + s1[I_ADD] - 48;
		if (K_ADD < 10)
		{
			STR_ADD[I_ADD + 1] = K_ADD + '0';
			K_ADD = 0;
		}
		else
		{
			STR_ADD[I_ADD + 1] = K_ADD + '0' - 10;
			K_ADD = 1;
		}
		I_ADD--;
	}
	if (K_ADD != 0)
		STR_ADD[I_ADD + 1] = K_ADD + '0';
	else
		STR_ADD[I_ADD + 1] = '0';
}
