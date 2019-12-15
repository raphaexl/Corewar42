/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pointer_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:30:51 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/09 16:04:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*display_pointer_hex(t_tab *tab)
{
	int			len_str;
	char		*str;
	uintmax_t	num;

	num = (unsigned long)(va_arg(tab->args, unsigned long int));
	if (!(str = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	len_str = ft_strlen(str) + 2;
	if (DIGIT >= len_str)
		RET_LEN += DIGIT;
	else
		RET_LEN += len_str;
	if (F_NEG != '-')
		display_space_zero(tab, ' ', DIGIT - len_str, 0);
	write(1, "0x", 2);
	ft_putstr(str);
	if (F_NEG == '-')
		display_space_zero(tab, ' ', DIGIT - len_str, 0);
	ft_strdel(&str);
	return (tab);
}
