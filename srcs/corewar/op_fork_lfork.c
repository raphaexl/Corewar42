/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:29:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/10 23:24:33 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_fork (0x0C) n’est pas suivie d’octet pour décrire les paramètres.
** Elle prend toujours un index et crée un nouveau programme
** qui s’exécute a partir de l’adresse:(PC + (premier paramètre % IDX_MOD))
** **************************************************************************
** op_lfork (0x0F) Comme fork sans le %IDX_MOD
** Cette opération modifie le carry.
*/

void	op_fork_lfork(t_vm *vm, t_process *process, int index)
{
	int16_t	new_pc;

	new_pc = 0;
	if (index == 1)
		new_pc = short_modulo(short_byte(vm, (process->pc + 1) % MEM_SIZE));
	else if (index == 2)
		new_pc = short_byte(vm, (process->pc + 1) % MEM_SIZE);
	new_pc += process->pc;
	process->pc_step = 3;
	copy_fork_lfork(vm, process, new_pc);
}
