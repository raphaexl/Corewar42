/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:31:13 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/10 23:31:15 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*increase_float_2(t_tab *tab, char *str, int len)
{
	char	*cpy;

	cpy = malloc(sizeof(char) * len);
	ft_strcpy(cpy, str);
	len--;
	if (PRECISION == 0)
	{
		if (cpy[len] == '5')
		{
			str = increase_float_3(tab, str, cpy, len);
			ft_strdel(&cpy);
			return (str);
		}
		if (cpy[len] >= '5')
		{
			str = increase_float_4(tab, str, cpy, len);
			ft_strdel(&cpy);
			return (str);
		}
	}
	str = increase_float_5(tab, str, cpy, len);
	ft_strdel(&cpy);
	return (str);
}

char	*increase_float_3(t_tab *tab, char *str, char *cpy, int len)
{
	len -= 2;
	if (cpy[len] < '5')
	{
		if (tt(tab, len) == 1)
			str[len] += 1;
		return (str);
	}
	else
		str[len] += 1;
	return (str);
}

char	*increase_float_4(t_tab *tab, char *str, char *cpy, int len)
{
	len -= 2;
	while (cpy[len] == '9')
	{
		str[len] = '0';
		len--;
	}
	str[len] += 1;
	if (len == -1)
		tab->k = 1;
	return (str);
}

char	*increase_float_5(t_tab *tab, char *str, char *cpy, int len)
{
	if (cpy[len] > '5')
	{
		len--;
		if (cpy[len] == '9')
		{
			while (cpy[len] == '9')
			{
				str[len] = '0';
				len--;
			}
			if (cpy[len] == '.')
			{
				len--;
				while (cpy[len] == '9')
				{
					str[len] = '0';
					len--;
				}
			}
		}
		str[len] += 1;
		if (len == -1)
			tab->k = 1;
	}
	return (str);
}
