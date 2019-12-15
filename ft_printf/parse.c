/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:15:40 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:16:37 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*parse_flag(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->flag[i])
	{
		while (tab->flag[i] == tab->copy[tab->i])
		{
			while (tab->copy[tab->i] == '#' && tab->i++)
				F_HASH = '#';
			while (tab->copy[tab->i] == '0' && tab->i++)
				F_0 = '0';
			while (tab->copy[tab->i] == '-' && tab->i++)
				F_NEG = '-';
			while (tab->copy[tab->i] == '+' && tab->i++)
				F_PLUS = '+';
			while (tab->copy[tab->i] == ' ' && tab->i++)
				F_SPACE = ' ';
			i = 0;
		}
		i++;
	}
	return (tab);
}

t_tab	*parse_digit(t_tab *tab)
{
	while (tab->copy[tab->i] >= '0' && tab->copy[tab->i] <= '9')
	{
		DIGIT *= 10;
		DIGIT += tab->copy[tab->i] - 48;
		tab->i++;
	}
	return (tab);
}

t_tab	*parse_precision(t_tab *tab)
{
	while (tab->copy[tab->i] == '.')
	{
		tab->i++;
		PRECISION = 0;
	}
	while (tab->copy[tab->i] >= '0' && tab->copy[tab->i] <= '9')
	{
		PRECISION *= 10;
		PRECISION += tab->copy[tab->i] - 48;
		tab->i++;
	}
	return (tab);
}

t_tab	*parse_flag_llh(t_tab *tab)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (tab->flag_llh[i])
	{
		while (tab->flag_llh[i] == tab->copy[tab->i])
		{
			tab->input_flag_llh[j] = tab->copy[tab->i];
			tab->input_flag_llh[j + 1] = '\0';
			tab->i++;
			j++;
		}
		i++;
	}
	return (tab);
}

t_tab	*parse_flag_cspdiouxxf(t_tab *tab)
{
	size_t	i;

	i = 0;
	while (tab->flag_cspdiouxxf[i])
	{
		if (tab->flag_cspdiouxxf[i] == tab->copy[tab->i])
			CSPDIOUXXF = tab->flag_cspdiouxxf[i];
		i++;
	}
	return (tab);
}
