/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:25:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 19:15:08 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

#define CYCLE_TO_CHECK (vm->cycle - vm->old_cycle)

void	visu_norm(t_vm *vm)
{
	if (!vm->visu)
		return ;
	vm->visu->end_game = 1;
	vm_visu(vm, vm->visu->bytes);
	endwin();
}

void	clash_of_champ(t_vm *vm)
{
	t_process *process;

	while (1)
	{
		if (vm->visu)
			vm_visu(vm, vm->visu->bytes);
		vm->cycle++;
		vm_log_and_dump(vm);
		process = vm->process;
		while (process)
		{
			exec_process(vm, process);
			process = process->next;
		}
		if (CYCLE_TO_CHECK == vm->cycle_to_die || vm->cycle_to_die <= 0)
		{
			kill_process(vm);
			reset_var(vm);
		}
		if (vm->process == NULL || (vm->visu && vm->visu->quit))
			break ;
	}
	visu_norm(vm);
}

void	exec_process(t_vm *vm, t_process *process)
{
	if (process->cycle_to_exec == 0)
	{
		process->op_code = vm->memory[process->pc];
		if (process->op_code > 0 && process->op_code < 17)
			process->cycle_to_exec = g_op_tab[process->op_code].cycle_to_wait;
	}
	if (process->cycle_to_exec > 0)
		process->cycle_to_exec--;
	if (process->cycle_to_exec == 0)
		exec_opcode(vm, process);
}

void	exec_opcode(t_vm *vm, t_process *process)
{
	int op;

	op = process->op_code;
	if (!(op > 0 && op < 17))
		process->pc_step = 1;
	else
	{
		if (g_op_tab[op].id_opcode > 0 && g_op_tab[op].id_opcode < 9)
			part_1(vm, process, op);
		else
			part_2(vm, process, op);
	}
	if (process->pc + process->pc_step < 0)
		process->pc += process->pc_step + MEM_SIZE;
	else
		process->pc = (process->pc + process->pc_step) % MEM_SIZE;
	process->pc_step = 0;
}
