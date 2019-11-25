/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:20:33 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 16:04:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_player		*ft_player_new(int number, char *name)
{
	t_player	*player;

	player = ft_memalloc(sizeof(t_player));
	player->id = 0;
	player->number = number;
	player->name = ft_strdup(name);
	player->next = NULL;
	return (player);
}

void		ft_player_push_back(t_player **players, t_player *new)
{
	t_player	*p;

	if (!players || !new)
		return ;
	if (!*players)
		*players = new;
	else
	{
		p = *players;
		while (p->next)
			p = p->next;
		if (p)
			p->next = new;
	}
}


t_player		*ft_players_copy(t_player *players)
{
	t_player	*player;

	player = 0;
	while (players)
	{
		ft_player_push_back(&player, ft_player_new(players->number, players->name));
		players = players->next;
	}
	return (player);
}

int		ft_players_length(t_player *players)
{
	if (!players)
		return (0);
	return (1 + ft_players_length(players->next));
}

void		ft_player_free(t_player **players)
{
	t_player *p;

	p = *players;
	while (p)
	{
		(*players) = (*players)->next;
		if (p->name)
			free(p->name);
		if (p->exec)
		{
			if (p->exec->code)
				free(p->exec->code);
			free(p->exec);
		}
		free(p);
		p = (*players);
	}
}
