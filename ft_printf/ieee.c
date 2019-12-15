/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieee.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:53:54 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:04:35 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_inf_nan(t_tab *tab)
{
	char str[20];

	binary(EXPONENT, 11, str);
	if (ft_strcmp(str, "11111111111") == 0 && SIGN == 1 && !I_LD)
	{
		tab->nan_inf = "-inf";
		return (1);
	}
	else if (ft_strcmp(str, "11111111111") == 0 && SIGN == 0 && !I_LD)
	{
		tab->nan_inf = "inf";
		return (2);
	}
	binary(EXPONENT_L, 15, str);
	if (I_LD && ft_strcmp(str, "111111111111111") == 0 && SIGN_L == 1)
	{
		tab->nan_inf = "-inf";
		return (1);
	}
	else if (I_LD && ft_strcmp(str, "111111111111111") == 0 && SIGN_L == 0)
	{
		tab->nan_inf = "inf";
		return (2);
	}
	return (0);
}

void	binary(int n, int i, char str[])
{
	int		k;
	int		len;

	len = 0;
	k = 0;
	while (--i >= 0)
	{
		k = n >> i;
		if (k & 1)
			str[len] = '1';
		else
			str[len] = '0';
		len++;
	}
	str[len] = '\0';
}
