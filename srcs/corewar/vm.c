/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:47:35 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 17:29:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	vm_init(t_vm *vm, int ac, char **av)
{
	int	i;

	i = -1;
	if (!(vm->cmd_arg = ft_memalloc(sizeof(t_cmd_arg))))
		malloc_error(vm);
	vm->cmd_arg->ac = ac;
	vm->cmd_arg->av = av;
	vm->cycle_to_die = CYCLE_TO_DIE;
	while (++i < 4)
		vm->cmd_arg->tab[i] = -1;
	parse(vm);
	if (!vm->visu)
		print_contestants(vm);
	vm_arena(vm);
	if (vm->visu)
		init_vs(vm);
}

void	vm_arena(t_vm *vm)
{
	t_player	*player;
	int			i;
	int			j;
	int			delta;

	i = -1;
	delta = MEM_SIZE / vm->nb_player;
	player = vm->player;
	while (++i < vm->nb_player)
	{
		j = -1;
		while (++j < (int)player->exec->head.prog_size)
			vm->memory[i * delta + j] = player->exec->code[j];
		player = player->next;
	}
}

void	add_process(t_vm *vm)
{
	t_player	*player;
	t_process	*process;
	int			i;

	player = vm->player;
	while (player)
	{
		i = 0;
		if (!(process = ft_memalloc(sizeof(t_process))))
			malloc_error(vm);
		process->player_id = player->number;
		process->pc = player->first_pc;
		process->reg[0] = player->number * -1;
		player->id = process->reg[0];
		process->last_live = 0;
		while (++i < 17)
			process->reg[i] = 0;
		process->next = vm->process;
		vm->process = process;
		vm->nbr_process++;
		if (player->next == NULL)
			vm->winner = player;
		player = player->next;
	}
}

void	vm_quit(t_vm *vm)
{
	if (vm->cmd_arg)
		free(vm->cmd_arg);
	if (vm->visu)
		free(vm->visu);
	if (vm->process)
		process_clean(&vm->process);
	if (vm->player)
		player_clean(&vm->player);
	vm->winner = NULL;
	exit(EXIT_SUCCESS);
}
