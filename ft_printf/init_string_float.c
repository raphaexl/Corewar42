/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_string_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:12:50 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/19 16:12:51 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_str_f(t_tab *tab, char *final_string)
{
	char *tmp;
	char *k;

	tab->tmp_4 = final_string;
	if (PRECISION == -1 || PRECISION >= 214783647)
		PRECISION = 6;
	if ((EXPONENT >= 0 && EXPONENT <= 1022) || I_ZP == 1)
		STR_RET = case_zero_point_2(tab, final_string);
	else
	{
		LEN_PI = ft_strlen(final_string);
		POS_POINT = LEN_PI - 52;
		k = ft_strndup(final_string, POS_POINT);
		PART_INT = ft_strjoin(k, ".");
		ft_strdel(&k);
		LEN_PF = ft_strlen(PART_INT);
		PART_FLOAT = ft_strndup_r(final_string, LEN_PI, LEN_PF - 1);
		STR_RET = ft_strjoin(PART_INT, PART_FLOAT);
		free_str(PART_INT, PART_FLOAT, NULL);
	}
	tmp = STR_RET;
	STR_RET = ft_strndup(STR_RET, PRECISION + LEN_PF + 1);
	LEN_STRING_RETURN = ft_strlen(STR_RET);
	init_str_f_4(tab);
	ft_strdel(&tmp);
}

void	init_str_f_4(t_tab *tab)
{
	if (STR_RET[LEN_STRING_RETURN - 1] >= 5)
		STR_RET = increase_float_2(tab, STR_RET, LEN_STRING_RETURN);
	if (PRECISION < 100 || STR_RET[LEN_STRING_RETURN - 1] == '0')
		STR_RET[LEN_STRING_RETURN - 1] = '\0';
	display_f_2(tab, STR_RET);
	ft_strdel(&STR_RET);
}

char	*case_zero_point_2(t_tab *tab, char *final_string)
{
	tab->ind = 1;
	if (PRECISION == 0)
		LEN_PF = 1;
	else
		LEN_PF = 2;
	if (!tab->y)
		final_string = test(tab, final_string);
	if (EXPONENT == 1023)
		final_string = ft_strjoin("1.", final_string);
	else
		final_string = ft_strjoin("0.", final_string);
	if (!tab->y)
		ft_strdel(&tab->tmp_3);
	return (final_string);
}

char	*test(t_tab *tab, char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (tab->input_float < 1.0)
	{
		tab->input_float = tab->input_float * 10;
		i++;
	}
	s = ft_strnew(i);
	i--;
	while (i > 0)
	{
		s[j] = '0';
		i--;
		j++;
		tab->lr++;
	}
	s[j] = '\0';
	tab->tmp_3 = ft_strjoin(s, str);
	ft_strdel(&str);
	ft_strdel(&s);
	return (tab->tmp_3);
}

int		tt(t_tab *tab, int len)
{
	len += 2;
	while (tab->tmp_4[len] != '\0')
	{
		if (tab->tmp_4[len] != '0')
		{
			len = 0;
			break ;
		}
		len++;
	}
	if (len == 0)
		return (1);
	return (0);
}
