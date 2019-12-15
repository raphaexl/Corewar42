/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs7.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:25:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 17:26:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void	vm_visu_event(char key, t_vm *vm)
{
	if (key == 'q')
	{
		vm->visu->quit = TRUE;
		vm->visu->end_game = 1;
		vm_winner(vm);
	}
	if (key == 'd' && vm->visu->visu_spd <= 63000)
		vm->visu->visu_spd += 3000;
	if (key == 'u' && vm->visu->visu_spd >= 3000)
		vm->visu->visu_spd -= 3000;
	if (key == 's')
		vm->visu->visu_event = 's';
	else
		vm->visu->visu_event = 'n';
}
