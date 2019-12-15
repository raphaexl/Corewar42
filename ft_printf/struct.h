/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 12:50:39 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 12:50:48 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "ft_printf.h"

typedef struct		s_tab
{
	union			u_double_float
	{
		double		input_double;
		struct		s_double_part
		{
			unsigned long	mantissa : 52;
			unsigned		exponent : 11;
			unsigned		sign : 1;
		}			s_d_parts;
	}				u_double;

	union			u_long_double
	{
		long double	input_long_double;
		struct		s_long_double_parts
		{
			unsigned long long	mantissa: 63;
			unsigned			integer : 1;
			unsigned			exponent:15;
			unsigned			sign: 1;

		}			s_ld_parts;
	}				u_ld;

	struct			s_init_string_float
	{
		int		len_part_int;
		int		len_part_float;
		int		len_string_return;
		int		pos_point;
		char	*part_int;
		char	*part_float;
		char	*string_return;
	}				s_init_str_f;

	struct			s_x
	{
		int		len;
		int		len_str;
		int		calc;
		int		calc_2;
		int		zero;
	}				s_hex_integer;

	struct			s_string_add
	{
		int		i;
		int		j;
		int		k;
		char	*str;

	}				s_str_add;

	va_list			args;

	const char		*format;
	char			*nan_inf;
	char			*mantissa_calc;
	char			*power_calc;
	char			*string_calc;
	char			*final_string;
	char			*result;
	char			*calc;
	char			*sub;
	char			*ret;
	char			*tmp_1;
	char			*tmp_2;
	char			*tmp_3;
	char			*tmp_4;
	char			*inter_index;
	char			*copy;
	char			*flag_cspdiouxxf;
	char			input_flag_cspdiouxxf;
	char			*flag_llh;
	char			input_flag_llh[2];
	char			*flag;
	char			input_flag[6];
	char			str[20];
	int				k;
	int				type_float_return;
	int				len_part_int;
	int				point;
	int				index_zero_point;
	int				y;
	int				x;
	int				lr;
	int				bias_double;
	int				bias_long_double;
	int				len;
	int				update_len;
	int				index;
	int				arr[5];
	int				ind;
	int				indd;
	int				return_len;
	long double		input_float;
	long int		precision;
	long int		digit;
	size_t			i;
}					t_tab;
#endif
