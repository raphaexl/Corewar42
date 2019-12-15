/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:31:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/10 23:35:08 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** 0x09 (zjmp) n’est pas suivie d’octet pour décrire les paramètres.
** Elle prend un index et fait un saut a cet index si le carry
*/

void	op_zjmp(t_vm *vm, t_process *process)
{
	short	pc_step;

	pc_step = short_modulo(short_byte(vm, (process->pc + 1) % MEM_SIZE));
	if (process->carry == 1)
	{
		process->pc = (process->pc + pc_step) % MEM_SIZE;
		process->pc_step = 0;
	}
	else
		process->pc_step = 3;
}
