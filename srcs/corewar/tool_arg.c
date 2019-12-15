/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:10:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 11:23:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	type_argument(t_process *process, unsigned char arg_type, int nbr_arg)
{
	int				i;
	unsigned char	tmp;

	i = -1;
	while (++i < nbr_arg)
	{
		tmp = (arg_type << (2 * i));
		process->args[i] = tmp >> 6;
	}
}

int		arg_is_valid(t_process *process, int nbr_arg)
{
	int i;

	i = -1;
	while (++i < nbr_arg)
	{
		if (process->args[i] == 0)
			return (0);
		if (process->args[i] == 1)
			if ((g_op_tab[process->op_code].args[i] & T_REG) == 0)
				return (0);
		if (process->args[i] == 2)
			if ((g_op_tab[process->op_code].args[i] & T_DIR) == 0)
				return (0);
		if (process->args[i] == 3)
			if ((g_op_tab[process->op_code].args[i] & T_IND) == 0)
				return (0);
	}
	return (1);
}

int		skip_byte(int arg_type, int nbr_param, int size)
{
	int		step;
	int		index;
	int		tmp;

	step = 0;
	index = 0;
	while (index < nbr_param)
	{
		tmp = arg_type >> (6 - 2 * index);
		arg_type -= arg_type >> (6 - 2 * index) * 1 << (6 - 2 * index);
		if (tmp != 0)
		{
			if (tmp == 2)
				step += size;
			else if (tmp == 1)
				step += 1;
			else
				step += 2;
		}
		index++;
	}
	return (step + 2);
}

short	short_byte(t_vm *vm, int pc)
{
	short	value;
	int		i;

	value = 0;
	i = -1;
	while (++i < 2)
		value = (value << 8) | vm->memory[(pc + i) % MEM_SIZE];
	return (value);
}

int		int_byte(t_vm *vm, int pc)
{
	int		value;
	int		i;

	value = 0;
	i = -1;
	while (++i < 4)
		value = (value << 8) | vm->memory[(pc + i) % MEM_SIZE];
	return (value);
}
