/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:26:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/10 23:17:21 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	part_1(t_vm *vm, t_process *process, int op)
{
	if (g_op_tab[op].id_opcode == 1)
		op_live(vm, process);
	if (g_op_tab[op].id_opcode == 2)
		op_ld_lld(vm, process, 1);
	if (g_op_tab[op].id_opcode == 3)
		op_st(vm, process);
	if (g_op_tab[op].id_opcode == 4)
		op_add_sub(vm, process, 1);
	if (g_op_tab[op].id_opcode == 5)
		op_add_sub(vm, process, 2);
	if (g_op_tab[op].id_opcode == 6)
		op_and_or_xor(vm, process, 1);
	if (g_op_tab[op].id_opcode == 7)
		op_and_or_xor(vm, process, 2);
	if (g_op_tab[op].id_opcode == 8)
		op_and_or_xor(vm, process, 3);
}

void	part_2(t_vm *vm, t_process *process, int op)
{
	if (g_op_tab[op].id_opcode == 9)
		op_zjmp(vm, process);
	if (g_op_tab[op].id_opcode == 10)
		op_ldi_lldi(vm, process, 1);
	if (g_op_tab[op].id_opcode == 11)
		op_sti(vm, process);
	if (g_op_tab[op].id_opcode == 12)
		op_fork_lfork(vm, process, 1);
	if (g_op_tab[op].id_opcode == 13)
		op_ld_lld(vm, process, 2);
	if (g_op_tab[op].id_opcode == 14)
		op_ldi_lldi(vm, process, 2);
	if (g_op_tab[op].id_opcode == 15)
		op_fork_lfork(vm, process, 2);
	if (g_op_tab[op].id_opcode == 16)
		op_aff(vm, process);
}
