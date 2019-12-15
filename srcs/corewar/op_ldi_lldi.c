/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi_lldi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 13:44:48 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/11 00:26:32 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_ldi                    ldi 3, %4, r1 (0x0a)
** Cette instruction prend 3 paramètres
** REG_SIZE octets a (PC + (S % IDX_MOD)) qu’on copie dans r1.
** S = (PC + (3 % IDX_MOD)) + value arg_2
** REG[arg_3] = (PC+S) % IDX_MOD
** ************************************************************************** *
** HEXDUMP 0A E4 00 03 00 04 01    | VM_MEMORY 10 228 0 3 0 4 1
** 0A == 10 == OP_CODE             | E4 ? 228 => 11[ind] 10[dir] 01[reg] + 00
** E4 == 228 == TYPE_ARGUMENT      | BINARY  == 11 10 01 00
** 00 CUZ SIZE OF T_IND = 2        | DECIMAL == 228
** 03 == 3 == 3                    | HEX     == E4
** 00 CUZ SIZE OF T_DIR = 2        | t_ind = 2 octet = 0 3
** 04 == 4 == %4                   | t_dir = 2 octet = 0 4
** 01 == 1 == r1                   | t_reg = 1 octet = 1
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 11 10 01 00 | 10 01 00 00 | 01 00 00 00
**                          {IND}         {DIR}         {REG}
** ************************************************************************** *
** op_lldi (0x0E) Comme ldi sans le %IDX_MOD.
** ************************************************************************** *
** Cette opération modifie le carry.
*/

#define PC (process->pc + pc_step)

static int	check_param(int arg_1, int arg_2, char arg_3)
{
	if (arg_1 == 0 && arg_2 == 0 && arg_3 > 0 && arg_3 < 17)
		return (1);
	return (0);
}

static void	help_ldi(t_vm *vm, t_process *process, t_arg *arg_1, t_arg *arg_2)
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

static void	help_lldi(t_vm *vm, t_process *process, t_arg *arg_1, t_arg *arg_2)
{
	ft_bzero(arg_1, sizeof(t_arg));
	ft_bzero(arg_2, sizeof(t_arg));
	arg_1->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	arg_2->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	value_without_modulo(vm, process, arg_1, process->args[0]);
	process->pc_step += step_add(process->args[0], arg_1->dir_size);
	value_without_modulo(vm, process, arg_2, process->args[1]);
	process->pc_step += step_add(process->args[1], arg_2->dir_size);
}

void		op_ldi_lldi(t_vm *vm, t_process *process, int index)
{
	unsigned char	arg_type;
	t_arg			arg_1;
	t_arg			arg_2;
	char			arg_3;
	short			pc_step;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 3);
	if (arg_is_valid(process, 3) == 1 && (process->pc_step += 2))
	{
		if (index == 1)
			help_ldi(vm, process, &arg_1, &arg_2);
		else if (index == 2)
			help_lldi(vm, process, &arg_1, &arg_2);
		arg_3 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		if (check_param(arg_1.error, arg_2.error, arg_3) == 1)
		{
			pc_step = int_modulo(arg_1.value + arg_2.value);
			process->reg[arg_3 - 1] = int_byte(vm, PC % MEM_SIZE);
		}
		process->pc_step += 1;
	}
	else
		process->pc_step += skip_byte(arg_type, 3, 2);
}
