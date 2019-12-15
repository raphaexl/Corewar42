/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_fork_lfork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:26:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 07:54:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	copy_fork_lfork(t_vm *vm, t_process *process, int pc)
{
	t_process	*new;
	t_process	*tmp;
	int			i;

	i = -1;
	if (!(new = ft_memalloc(sizeof(t_process))))
		malloc_error(vm);
	new->player_id = process->player_id;
	new->carry = process->carry;
	new->last_live = process->last_live;
	while (++i < 17)
		new->reg[i] = process->reg[i];
	new->pc = pc % MEM_SIZE;
	new->cycle_to_exec = 0;
	new->pc_step = 0;
	new->id = vm->process ? vm->process->id + 1 : 0;
	tmp = vm->process;
	vm->process = new;
	new->next = tmp;
	vm->nbr_process++;
}
