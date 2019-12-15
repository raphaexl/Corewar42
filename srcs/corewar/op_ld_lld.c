/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:39:11 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/10 23:26:04 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_ld                    ld %12314,r4 (0x02)
** Cette instruction prend 2 paramètres [ {dir|ind} | reg ]
** Elle load la valeur du premier paramètre dans le registre.
** ************************************************************************** *
** HEXDUMP 02 90 00 00 30 1A 04    | VM_MEMORY  2 144 0 0 48 26 4
** 02 == 2   == OP_CODE            | 90 ? 144 => 10[dir] 01[reg] 00 00
** 90 == 144 == TYPE_ARGUMENT      | BINARY  == 10 01 00 00
** 00 00 CUZ SIZE OF T_DIR = 4     | DECIMAL == 144
** 30 1A == 48 26  == 12314        | HEX     == 90
** 04 == 4 == r4                   | t_dir = 4 octet = 0 0 48 26
**                                 | t_reg = 1 octet = 4
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 10 01 00 00 [dir] | 01 00 00 00 [reg]
** OP_LD CALC -> ld 34,r3 (PC + (34 % IDX_MOD)) dans le registre r3.
** ************************************************************************** *
** op_lld (0x0D) Comme ld sans le %IDX_MOD.
** ************************************************************************** *
** Cette opération modifie le carry.
*/

static int		check_param(int arg_1, char arg_2)
{
	if (arg_1 == 0 && arg_2 > 0 && arg_2 < 17)
		return (1);
	return (0);
}

static void		help(t_vm *vm, t_process *process, t_arg *arg_1, int index)
{
	ft_bzero(arg_1, sizeof(t_arg));
	arg_1->dir_size = g_op_tab[vm->memory[(process->pc)]].size_dir;
	if (index == 1)
		value_with_modulo(vm, process, arg_1, process->args[0]);
	else if (index == 2)
		value_without_modulo(vm, process, arg_1, process->args[0]);
	process->pc_step += step_add(process->args[0], arg_1->dir_size);
}

static void		carry(t_process *process, char arg_2)
{
	if (process->reg[arg_2 - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void			op_ld_lld(t_vm *vm, t_process *process, int index)
{
	unsigned char	arg_type;
	t_arg			arg_1;
	char			arg_2;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 2);
	if (arg_is_valid(process, 2) == 1 && (process->pc_step += 2))
	{
		help(vm, process, &arg_1, index);
		arg_2 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		process->pc_step += 1;
		if (check_param(arg_1.error, arg_2) == 1)
		{
			process->reg[arg_2 - 1] = arg_1.value;
			carry(process, arg_2);
		}
	}
	else
		process->pc_step = skip_byte(arg_type, 2, 4);
}
