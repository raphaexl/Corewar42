/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:31:27 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/23 16:36:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		ft_read(t_vm	*vm)
{
	t_player	*player;

	if (!vm->players)
		return (-1);
	player = vm->players;
	while (player)
	{
		if (!(player->exec = ft_read_code(player->name)))
			return (-1);
		player = player->next;
	}
	return (0);
}
