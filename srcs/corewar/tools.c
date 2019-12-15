/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:34:11 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/11 00:25:39 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

int		check_is_digit_string(char *av)
{
	int		i;

	i = -1;
	while (av[++i])
	{
		if (!ft_isdigit(av[i]))
			return (0);
	}
	return (1);
}

int		step_add(int index_arg, int dir_size)
{
	if (index_arg == 1)
		return (1);
	if (index_arg == 2)
		return (4 - (2 * dir_size));
	if (index_arg == 3)
		return (2);
	return (0);
}

short	short_modulo(short value)
{
	int		sign;

	if (value < 0)
		sign = -1;
	else
		sign = 1;
	value = value * sign;
	value = value % IDX_MOD;
	return (value * sign);
}

int		int_modulo(int value)
{
	int sign;

	if (value < 0)
		sign = -1;
	else
		sign = 1;
	value = value * sign;
	value = value % IDX_MOD;
	return (value * sign);
}
