/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:23:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 17:06:37 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	ft_players_print(t_player *players)
{
	while (players)
	{
		puts("-----------------------------------");
		printf("Id : %d Number : %d File Name : %s\n", players->id, players->number, players->name);
		printf("Name %s Comment : %s\n", players->exec->head.prog_name, players->exec->head.comment);
		puts("-----------------------------------");
		players = players->next;
	}
}
