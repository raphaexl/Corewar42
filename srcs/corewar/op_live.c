/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:29:52 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 21:22:17 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** 0x01 (live)	Suivie de 4 octets qui représente le numéro du joueur.
** Cette instruction indique que ce joueur est en vie.
** (pas d’octet de codage des paramètres).
*/

void	op_live(t_vm *vm, t_process *process)
{
	t_player	*player;
	int			id;

	player = vm->player;
	id = int_byte(vm, (process->pc + 1) % MEM_SIZE);
	while (player)
	{
		if (player->id == id)
		{
			vm->winner = player;
			player->live++;
			break ;
		}
		player = player->next;
	}
	process->last_live = vm->cycle;
	vm->lives++;
	process->pc_step = 5;
}
