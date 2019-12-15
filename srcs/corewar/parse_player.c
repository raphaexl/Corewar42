/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:32:47 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 16:37:58 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void		parse_player(t_vm *vm)
{
	t_player	*new;
	int			i;

	i = 0;
	while (++i < vm->cmd_arg->ac)
	{
		if (cmp_number(vm->cmd_arg->av[i]))
			i = i + 3;
		if (i >= vm->cmd_arg->ac)
			break ;
		if (cmp_player_cor(vm->cmd_arg->av[i]))
		{
			if ((i - 2) >= 1 && cmp_number(vm->cmd_arg->av[i - 2]))
				continue;
			new = create_new_player(vm);
			new->name = vm->cmd_arg->av[i];
			new->number = search_id_player(vm);
			vm->nb_player++;
		}
	}
}

int			search_id_player(t_vm *vm)
{
	t_player	*p;
	int			i;

	i = -1;
	p = vm->player;
	while (p)
	{
		if (p->number)
			vm->cmd_arg->tab[p->number - 1] = p->number;
		p = p->next;
	}
	while (++i < 4)
	{
		if (vm->cmd_arg->tab[i] == -1)
		{
			vm->cmd_arg->tab[i] = i + 1;
			break ;
		}
	}
	return (vm->cmd_arg->tab[i]);
}

void		check_player(t_vm *vm)
{
	t_player	*player;
	int			index;

	index = 0;
	player = vm->player;
	if (vm->nb_player > 4 || vm->nb_player == 0)
		vm_error(vm, ARGS_ERROR);
	while (player)
	{
		if (vm->nb_player == 1 && player->number != 1)
			index = -1;
		if (vm->nb_player == 3 && player->number == 4)
			index = -1;
		if (vm->nb_player == 2 && (player->number == 3 || player->number == 4))
			index = -1;
		player = player->next;
	}
	if (index == -1)
		vm_error(vm, ARGS_ERROR);
	player = vm->player;
	if (vm->nb_player >= 2)
		swap_player(vm, player);
}

void		pos_pc_player(t_vm *vm)
{
	t_player	*player;
	int			cum;
	int			diff;

	diff = 4096 / vm->nb_player;
	cum = 0;
	player = vm->player;
	while (player)
	{
		player->first_pc = cum;
		cum += diff;
		player = player->next;
	}
}
