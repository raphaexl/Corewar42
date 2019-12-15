/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_stdarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:24:19 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:28:32 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		type_decimal(t_tab *tab)
{
	intmax_t	num;

	if (ft_strcmp(tab->input_flag_llh, "h") == 0)
		num = (short)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->input_flag_llh, "hh") == 0)
		num = (signed char)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->input_flag_llh, "l") == 0)
		num = (long)(va_arg(tab->args, long int));
	else if (ft_strcmp(tab->input_flag_llh, "ll") == 0)
		num = (long long)(va_arg(tab->args, long long int));
	else
		num = (int)(va_arg(tab->args, int));
	return (num);
}

uintmax_t		type_octal_integer(t_tab *tab)
{
	uintmax_t	num;

	if (ft_strcmp(tab->input_flag_llh, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else if (ft_strcmp(tab->input_flag_llh, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	return (num);
}

uintmax_t		type_hex_integer(t_tab *tab)
{
	uintmax_t	num;

	if (ft_strcmp(tab->input_flag_llh, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (ft_strcmp(tab->input_flag_llh, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	return (num);
}

uintmax_t		type_u_decimal(t_tab *tab)
{
	uintmax_t	num;

	if (ft_strcmp(tab->input_flag_llh, "hh") == 0)
		num = (unsigned char)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "h") == 0)
		num = (unsigned short)(va_arg(tab->args, unsigned int));
	else if (ft_strcmp(tab->input_flag_llh, "ll") == 0)
		num = (unsigned long long)(va_arg(tab->args, unsigned long long int));
	else if (ft_strcmp(tab->input_flag_llh, "l") == 0)
		num = (unsigned long)(va_arg(tab->args, unsigned long int));
	else
		num = (unsigned int)(va_arg(tab->args, unsigned int));
	return (num);
}

long double		get_type_float(t_tab *tab)
{
	long double	num;

	if (ft_strcmp(tab->input_flag_llh, "L") == 0 && (I_LD = 1))
	{
		num = va_arg(tab->args, long double);
		NUMBER_LD = num;
	}
	else if (ft_strcmp(tab->input_flag_llh, "l") == 0)
	{
		num = va_arg(tab->args, double);
		NUMBER_DOUBLE = num;
	}
	else
	{
		num = va_arg(tab->args, double);
		NUMBER_DOUBLE = num;
	}
	if (num != num && (tab->type_float_return = 1))
	{
		if ((SIGN == 0 && !I_LD) || SIGN_L == 0)
			tab->nan_inf = "nan";
		else if ((SIGN == 1 && !I_LD) || SIGN_L == 1)
			tab->nan_inf = "-nan";
	}
	return (num);
}
