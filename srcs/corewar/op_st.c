/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:57:38 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/13 13:16:55 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_st                   st r4,34 (0x02)
** Cette instruction prend 2 paramètres [ reg | {reg|ind} ]
** store la valeur de r4 a l’adresse(PC + (34 % IDX_MOD))
** st r3,r8 copie r3 dans r8
** ************************************************************************** *
** HEXDUMP 03 70 04 00 22          | VM_MEMORY  3 112 4 0 34
** 03 == 3 == OP_CODE              | 70 ? 112 => 01[reg] 11[ind] 00 00
** 70 == 112 == TYPE_ARGUMENT      | BINARY  == 01 11 00 00
** 04 == 4 == r4                   | DECIMAL == 112
** 00 CUZ SIZE OF T_IND = 2        | HEX     == 70
** 22 == 34 == 34                  | t_reg = 1 octet = 4
**                                 | t_ind = 2 octet = 0 34
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 01 11 00 00 [reg] | 11 00 00 00 [ind]
*/

#define PC (process->pc + process->pc_step)

static void	write_op(t_vm *vm, t_process *process, int value, int pc_step)
{
	int		i;
	char	*s;

	i = -1;
	s = (char*)&value;
	if (pc_step < 0)
		pc_step += 4096;
	while (++i < 4)
		vm->memory[(process->pc + pc_step + i) % MEM_SIZE] = s[3 - i];
}

static int	check_1(t_vm *vm, t_process *process, char arg_1, int type_arg)
{
	if (arg_1 > 0 && arg_1 < 17 && type_arg == 3)
	{
		write_op(vm, process, process->reg[arg_1 - 1], process->count_st_sti);
		return (1);
	}
	return (0);
}

static void	check_2(t_process *process, char arg_1, char arg_2)
{
	if (arg_1 > 0 && arg_1 < 17 && arg_2 > 0 && arg_2 < 17)
		process->reg[arg_2 - 1] = process->reg[arg_1 - 1];
}

static void	check_3(t_process *process)
{
	if (process->args[1] == 1)
		process->pc_step += 1;
	else
		process->pc_step += 2;
}

void		op_st(t_vm *vm, t_process *process)
{
	unsigned char	arg_type;
	char			arg_1;
	char			arg_2;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 2);
	if (arg_is_valid(process, 2) == 1 && (process->pc_step += 2))
	{
		arg_1 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		process->pc_step++;
		arg_2 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		process->count_st_sti = short_modulo(short_byte(vm, PC % MEM_SIZE));
		check_3(process);
		if (check_1(vm, process, arg_1, process->args[1]) == 0)
			check_2(process, arg_1, arg_2);
	}
	else
		process->pc_step = skip_byte(arg_type, 2, 4);
}
