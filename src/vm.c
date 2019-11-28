/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 17:11:31 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:35:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

void	ft_vm_load(t_vm *vm)
{
	ft_game_load(vm);
}

void	ft_vm_clean(t_vm *vm)
{
	ft_player_free(&vm->args.players);
//	ft_player_free(&vm->game.players);
	ft_carriage_free(&vm->game.carriage);
	exit(EXIT_SUCCESS);
}
