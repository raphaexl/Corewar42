/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_long_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:31:17 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/10 23:20:33 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*case_long_double(t_tab *tab)
{
	char	*s1;
	char	*s2;

	s1 = mantissa_long_double(tab);
	if (EXPONENT_L - BIAS_LD < 0)
		s2 = power(tab, 5, -EXPONENT_L + BIAS_LD);
	else if (EXPONENT_L - BIAS_LD > 0)
		s2 = power(tab, 2, EXPONENT_L - BIAS_LD);
	else
	{
		init_str_f_3(tab, s1);
		ft_strdel(&s1);
		return (tab);
	}
	init_str_f_3(tab, no_zero(tab, string_multi(tab, s2, s1)));
	free_str(s1, s2, NULL);
	return (tab);
}

char	*mantissa_long_double(t_tab *tab)
{
	int	i;
	int	len;

	i = 1;
	tab->result = str_zero(63);
	while (MANTISSA_L)
	{
		if (MANTISSA_L & 1)
		{
			tab->calc = power(tab, 5, 63 - i + 1);
			tab->calc = join(tab->calc, str_zero(i - 1));
		}
		else
			tab->calc = NULL;
		if (tab->calc != NULL)
			tab->result = string_add(tab, tab->result, tab->calc);
		MANTISSA_L = MANTISSA_L >> 1;
		i++;
		ft_strdel(&tab->calc);
	}
	len = ft_strlen(tab->result);
	tab->sub = ft_strsub(tab->result, len - 63, len);
	if (mantissa_long_double_2(tab) == 1)
		return (tab->sub);
	return (tab->ret);
}

void	init_str_f_3(t_tab *tab, char *final_string)
{
	if (PRECISION == -1)
		PRECISION = 6;
	if ((EXPONENT_L > 0 && EXPONENT_L <= 16382) || I_ZP == 1)
		STR_RET = case_zero_point_2(tab, final_string);
	else
	{
		LEN_PI = ft_strlen(final_string);
		POS_POINT = LEN_PI - 63;
		PART_INT = ft_strjoin(ft_strndup(final_string, POS_POINT), ".");
		LEN_PF = ft_strlen(PART_INT);
		PART_FLOAT = ft_strndup_r(final_string, LEN_PI, LEN_PF - 1);
		STR_RET = ft_strjoin(PART_INT, PART_FLOAT);
		free_str(PART_INT, PART_FLOAT, NULL);
	}
	STR_RET = ft_strndup(STR_RET, PRECISION + LEN_PF + 1);
	LEN_STRING_RETURN = ft_strlen(STR_RET);
	if (STR_RET[LEN_STRING_RETURN - 1] >= 5)
		STR_RET = increase_float_2(tab, STR_RET, LEN_STRING_RETURN);
	STR_RET[LEN_STRING_RETURN - 1] = '\0';
	display_f_2(tab, STR_RET);
	ft_strdel(&STR_RET);
}

int		mantissa_long_double_2(t_tab *tab)
{
	if (!EXPONENT_L)
	{
		ft_strdel(&tab->result);
		return (1);
	}
	tab->ret = ft_strjoin((INTEGER == 0 ? "0" : "1"), tab->sub);
	free_str(tab->sub, tab->result, NULL);
	return (0);
}
