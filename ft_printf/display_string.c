/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:32:17 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:32:33 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_string(t_tab *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (PRECISION > -1 && str)
		str = ft_strndup(str, PRECISION);
	else if (PRECISION == -1 && str)
		str = ft_strdup(str);
	else if (PRECISION > -1 && !str)
		str = ft_strndup("(null)", PRECISION);
	else if (PRECISION == -1 && !str)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	RET_LEN += len;
	if (F_0 == '0' && F_NEG != '-')
		display_space_zero(tab, '0', DIGIT - len, 1);
	else if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - len, 1);
	ft_putstr(str);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - len, 1);
	ft_strdel(&str);
	return (tab);
}
