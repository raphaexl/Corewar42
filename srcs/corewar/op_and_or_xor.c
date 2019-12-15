/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and_or_xor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:21:08 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/10 23:23:48 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_and (0x06)   p1 & p2 -> p3 le paramètre 3 et toujours un registre.
** op_or  (0x07)   Même que and mais avec le ou (| du c).
** op_xor (0x08)   Même que and mais avec le ou exclusif (^ du c).
** Cette opération modifie le carry.
** ************************************************************************** *
**                          and %10,50,r5
** HEXDUMP 06 B4 00 00 00 0A 00 32 05 | VM_MEMORY  6 180 0 0 0 10  0 50 5
** 06 == 6   == OP_CODE               | B4 ? 180 => 10[dir]11[ind]01[reg] + 00
** B4 == 180 == TYPE_ARGUMENT         | BINARY == 10 11 01 00
** 00 00 00 CUZ SIZE OF T_DIR = 4     | DECIMAL == 180
** 0A == 10 == %10                    | HEX == B4
** 00 CUZ SIZE OF T_IND = 2           | t_dir = 4 octet 0 0 0 10
** 32 == 50 == 50                     | t_ind = 2 octet 0 50
** 05 == 5  == r5                     | t_reg = 1 octet 5
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 10 11 01 00 [dir] | 11 01 00 00 [ind] | 01 00 00 00 |
** OP_AND CALC -> registre 5 = %10 & 50
**                  (%10)         == 00 00 10 10
**                 &
**                  pc + (50%512) == 00 00 00 00
**                 =               ---------------
**                                   00 00 00 00
** ************************************************************************** *
*/

static int		check_param(int arg_1, int arg_2, char arg_3)
{
	if (arg_1 == 0 && arg_2 == 0 && arg_3 > 0 && arg_3 < 17)
		return (1);
	return (0);
}

static void		calc(t_vm *vm, t_process *process, t_arg *arg_1, t_arg *arg_2)
{
	ft_bzero(arg_1, sizeof(t_arg));
	ft_bzero(arg_2, sizeof(t_arg));
	arg_1->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	arg_2->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	value_with_modulo(vm, process, arg_1, process->args[0]);
	process->pc_step += step_add(process->args[0], arg_1->dir_size);
	value_with_modulo(vm, process, arg_2, process->args[1]);
	process->pc_step += step_add(process->args[1], arg_2->dir_size);
}

static void		carry(t_process *process, char arg_3)
{
	if (process->reg[arg_3 - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void			op_and_or_xor(t_vm *vm, t_process *process, int index)
{
	unsigned char	arg_type;
	t_arg			arg_1;
	t_arg			arg_2;
	char			arg_3;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 3);
	if (arg_is_valid(process, 3) == 1 && (process->pc_step += 2))
	{
		calc(vm, process, &arg_1, &arg_2);
		arg_3 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		if (check_param(arg_1.error, arg_2.error, arg_3) == 1)
		{
			if (index == 1)
				process->reg[arg_3 - 1] = arg_1.value & arg_2.value;
			else if (index == 2)
				process->reg[arg_3 - 1] = arg_1.value | arg_2.value;
			else if (index == 3)
				process->reg[arg_3 - 1] = arg_1.value ^ arg_2.value;
			carry(process, arg_3);
		}
		process->pc_step += 1;
	}
	else
		process->pc_step += skip_byte(arg_type, 3, 4);
}
