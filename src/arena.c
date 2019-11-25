/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:50:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 17:12:20 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		ft_arena_print(t_vm *vm)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			printf("%x ", vm->memory[j + i * 64]);
		}
		printf("\n");
	}
}

void		ft_arena_debug(t_vm *vm)
{
	vm->nb_players = ft_players_length(vm->players);
	printf("\nPosition : %d : %x\n", 0, ft_get_memory_byte(vm->memory, 0));
}

void		ft_arena_init(t_vm	*vm)
{
	int			offset;
	int			delta;
	int			i;
	int			j;
	t_player	*player;

	offset = 0;
	vm->nb_players = ft_players_length(vm->players);
	delta = MEM_SIZE / vm->nb_players;
	i = -1;
	player = vm->players;
	while (++i < vm->nb_players)
	{
		j = -1;
		while (++j < (int )player->exec->head.prog_size)
			vm->memory[i * delta + j] = player->exec->code[j];
		player = player->next;
	}
}
