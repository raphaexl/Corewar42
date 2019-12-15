/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:33:30 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 13:12:23 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

static int	function(int shift, int arg_type, int dir_size)
{
	int	size_to_skip;

	size_to_skip = 0;
	if (((arg_type >> shift) & 3) == REG_CODE)
		size_to_skip += 1;
	else if (((arg_type >> shift) & 3) == DIR_CODE)
		size_to_skip += dir_size;
	else if (((arg_type >> shift) & 3) == IND_CODE)
		size_to_skip += IND_SIZE;
	return (size_to_skip);
}

int			ft_skip_bytes(unsigned char arg_type, int nbr_param, int dir_size)
{
	int	size_to_skip;

	(void)nbr_param;
	if (!arg_type)
		return (dir_size + 1);
	size_to_skip = 2;
	size_to_skip += function(2, arg_type, dir_size);
	size_to_skip += function(4, arg_type, dir_size);
	size_to_skip += function(6, arg_type, dir_size);
	return (size_to_skip);
}
