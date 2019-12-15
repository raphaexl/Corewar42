/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:34:24 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/11 00:24:26 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

#define PC (p->pc + p->pc_step)

void	value_with_modulo(t_vm *vm, t_process *p, t_arg *arg, int type_arg)
{
	short	value;

	if (type_arg == 1)
	{
		value = vm->memory[PC % MEM_SIZE];
		if (value > 0 && value < 17)
			arg->value = p->reg[value - 1];
		else
			arg->error = 1;
	}
	if (type_arg == 2)
		arg->value = value_tdir(vm, p, arg->dir_size);
	if (type_arg == 3)
	{
		value = short_modulo(short_byte(vm, PC % MEM_SIZE));
		arg->value = int_byte(vm, (p->pc + value) % MEM_SIZE);
	}
}

void	value_without_modulo(t_vm *vm, t_process *p, t_arg *arg, int type_arg)
{
	short	value;

	if (type_arg == 1)
	{
		value = vm->memory[PC % MEM_SIZE];
		if (value > 0 && value < 17)
			arg->value = p->reg[value - 1];
		else
			arg->error = 1;
	}
	if (type_arg == 2)
		arg->value = value_tdir(vm, p, arg->dir_size);
	if (type_arg == 3)
	{
		value = short_byte(vm, PC % MEM_SIZE);
		arg->value = int_byte(vm, (p->pc + value) % MEM_SIZE);
	}
}

int		value_tdir(t_vm *vm, t_process *process, int dir_size)
{
	int	value;

	if (dir_size == 1)
		value = short_byte(vm, (process->pc + process->pc_step) % MEM_SIZE);
	else
		value = int_byte(vm, (process->pc + process->pc_step) % MEM_SIZE);
	return (value);
}
