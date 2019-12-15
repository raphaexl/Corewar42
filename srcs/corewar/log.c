/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:50:07 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 17:32:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	vm_log_and_dump(t_vm *vm)
{
	if (!vm->visu && (vm->cycle - 1) && (vm->cycle == (vm->nb_dump + 1)))
	{
		if (vm->dump == DUMP_32)
			vm_arena_display_32(vm);
		else if (vm->dump == DUMP_64)
			vm_arena_display_64(vm);
		vm_quit(vm);
	}
	if ((vm->log == CYCLE_LOG) && !vm->visu)
		ft_printf("It is now cycle %d\n", vm->cycle);
}

void	vm_arena_display_32(t_vm *vm)
{
	int i;
	int j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		while (++j < 64)
		{
			if (!((j + i * 64) % 32))
				ft_printf("0x%.4x : ", j + i * 64);
			ft_printf("%02x ", vm->memory[j + i * 64]);
			if ((j + i * 64) && !((j + i * 64 + 1) % 32))
				ft_printf("\n");
		}
	}
}

void	vm_arena_display_64(t_vm *vm)
{
	int i;
	int j;

	i = -1;
	while (++i < 64)
	{
		j = -1;
		ft_printf("0x%.4x : ", (j + 1) + i * 64);
		while (++j < 64)
			ft_printf("%02x ", vm->memory[j + i * 64]);
		ft_printf("\n");
	}
}
