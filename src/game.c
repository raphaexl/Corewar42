/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:08:07 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:34:23 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

// Game Options Setting the value of the last player to say he is alive

t_player	*ft_player_highest_number(t_player *players)
{
	t_player	*p;
	t_player	*best;
	int			number;

	if (!players)
		return (NULL);
	p = players;
	best = players;
	number = p->number;
	while (p)
	{
		if (p->number > number)
		{
			best = p;
			number = p->number;
		}
		p = p->next;
	}
	return (best);
}

void		ft_game_load(t_vm *vm)
{
	t_game	game;


	ft_bzero(&game, sizeof(t_game));
	game.cycles = 0;
	game.nb_lives = 0;
	game.cycles_to_die = CYCLE_TO_DIE;
	game.nb_checks = 0;
	game.players = vm->args.players;
	//game->players = ft_players_copy(vm->players);
	game.last_alive_player = ft_player_highest_number(game.players);
	vm->game = game;
}


void		ft_update(t_game *game)
{
	(void)game;
}
