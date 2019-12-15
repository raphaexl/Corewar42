/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:33:35 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:34:28 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_tab	*tab;
	int		len;

	if (!(tab = (t_tab*)malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	tab = init(tab);
	if (format)
	{
		va_start(tab->args, format);
		RET_LEN = parse_init(tab);
		va_end(tab->args);
	}
	len = RET_LEN;
	free(tab);
	return (len);
}

int		parse_init(t_tab *tab)
{
	while (tab->copy[tab->i])
	{
		if (tab->copy[tab->i] == '%')
		{
			re_init(tab);
			init_function(tab);
		}
		else
		{
			write(1, &tab->copy[tab->i], 1);
			RET_LEN++;
		}
		tab->i++;
	}
	return (RET_LEN);
}
