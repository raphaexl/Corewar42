/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_kill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:25:18 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/11 19:45:00 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	kill_process(t_vm *vm)
{
	t_process *process;
	t_process *p_1;
	t_process *p_2;

	process = vm->process;
	p_2 = NULL;
	while (process)
	{
		if (process->last_live <= vm->old_cycle || vm->cycle_to_die <= 0)
		{
			p_1 = process;
			process = process->next;
			kill(vm, p_1, p_2);
		}
		else
		{
			p_2 = process;
			process = process->next;
		}
	}
}

void	kill(t_vm *vm, t_process *p_1, t_process *p_2)
{
	if (p_2 != NULL)
		p_2->next = p_1->next;
	else
		vm->process = p_1->next;
	if (vm->log == DEATH_LOG)
		ft_printf("Process %d declared dead on cycles %d (CTD %d)\n",
				p_1->id + 1, vm->cycle, vm->cycle_to_die);
	free(p_1);
	vm->nbr_process--;
}

void	reset_var(t_vm *vm)
{
	t_player *player;

	player = vm->player;
	vm->check++;
	while (player)
	{
		player->live = 0;
		player = player->next;
	}
	if (vm->check == MAX_CHECKS || vm->lives >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		if ((vm->log == CYCLE_LOG) && !vm->visu)
			ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		vm->check = 0;
	}
	vm->lives = 0;
	vm->old_cycle = vm->cycle;
}
