/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:20:43 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/12 22:48:32 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	ft_parse_args(t_vm *vm, int ac, char *av[])
{
	int			i;
	int			j;
	int			set;
	int			tab[8];
	t_player	*player;

	i = 0;
	if (ac < 2)
		return ;
	while (++i < ac)
		if (ft_champion_name(av[i]) && ft_players_length(vm->players) < MAX_PLAYERS)
			ft_player_push_back(&vm->players, ft_player_new(i, av[i]));
	i = 0;
	set = 0;
	player = vm->players;
	ft_memset(tab, -1, sizeof(tab));
	j = -1;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-n"))
		{
			if (i + 1 < ac && av[i + 1][0]  >= '0' &&  av[i + 1][0] <= '4')  
				set = av[i + 1][0] - '0'; 
		}
		if (ft_champion_name(av[i]) && player)
		{
			tab[++j] = -1;
			if (set)
			{
				player->number = set;
				tab[j] = 0;
				tab[j + 4] = set;
			}
			set = 0;
			player = player->next;	
		}
	}
	player = vm->players;
	j = -1;
	while (player)
	{
		if (tab[++j] != 0)
		{
			player->number = ft_nonassigned(tab);
			tab[j + 4] = player->number;
		}
		else
		{
			/* May Be for when we reapeat ourselves */
		//	player->number = ft_nonassigned(tab);
		//	tab[j + 4] = player->number;
		}
		player = player->next;	
	}
}
