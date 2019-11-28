/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 22:50:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:24:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void		ft_arena_print(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			printf("%x ", game->memory[j + i * 64]);
		}
		printf("\n");
	}
}

void		ft_arena_debug(t_game *game)
{
	game->nb_players = ft_players_length(game->players);
	printf("\nPosition : %d : %x\n", 0, ft_get_memory_byte(game->memory, 0));
}

void		ft_arena_init(t_game	*game)
{
	int			offset;
	int			delta;
	int			i;
	int			j;
	t_player	*player;

	offset = 0;
	game->nb_players = ft_players_length(game->players);
	delta = MEM_SIZE / game->nb_players;
	i = -1;
	player = game->players;
	while (++i < game->nb_players)
	{
		j = -1;
		while (++j < (int )player->exec->head.prog_size)
			game->memory[i * delta + j] = player->exec->code[j];
		player = player->next;
	}
}
