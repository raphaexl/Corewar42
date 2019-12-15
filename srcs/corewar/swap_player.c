/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:33:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/10 23:45:44 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	swap_player(t_vm *vm, t_player *player)
{
	t_player	*tmp1;
	t_player	*tmp2;
	t_player	*tmp3;
	t_player	*tmp4;

	while (player)
	{
		if (player->number == 1)
			tmp1 = player;
		if (player->number == 2)
			tmp2 = player;
		if (player->number == 3)
			tmp3 = player;
		if (player->number == 4)
			tmp4 = player;
		player = player->next;
	}
	if (vm->nb_player == 4)
		case_4(tmp1, tmp2, tmp3, tmp4);
	if (vm->nb_player == 3)
		case_3(tmp1, tmp2, tmp3);
	if (vm->nb_player == 2)
		case_2(tmp1, tmp2);
	vm->player = tmp1;
}

void	case_4(t_player *tmp1, t_player *tmp2, t_player *tmp3, t_player *tmp4)
{
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	tmp3->next = tmp4;
	tmp4->next = NULL;
}

void	case_3(t_player *tmp1, t_player *tmp2, t_player *tmp3)
{
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	tmp3->next = NULL;
}

void	case_2(t_player *tmp1, t_player *tmp2)
{
	tmp1->next = tmp2;
	tmp2->next = NULL;
}
