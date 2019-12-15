/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:43:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 16:38:16 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void		parse_dump(t_vm *vm, char **av, int index)
{
	if (cmp_dump(av[index]) == 1)
	{
		if (!av[index + 1])
			vm_error(vm, ARGS_ERROR);
		if (check_is_digit_string(av[index + 1]) == 0)
			vm_error(vm, ARGS_ERROR);
		if (vm->nb_dump)
			vm_error(vm, ARGS_ERROR);
		vm->nb_dump = ft_atoi(av[index + 1]);
		if (vm->nb_dump < 1)
			vm_error(vm, ARGS_ERROR);
		if (!ft_strcmp(av[index], "-dump"))
			vm->dump = DUMP_32;
		else if (!ft_strcmp(av[index], "-d"))
			vm->dump = DUMP_64;
	}
}

void		parse_log(t_vm *vm, char **av, int index)
{
	if (cmp_log(av[index]) == 1)
	{
		if (!av[index + 1])
			vm_error(vm, ARGS_ERROR);
		if (check_is_digit_string(av[index + 1]) == 0)
			vm_error(vm, ARGS_ERROR);
		vm->log = ft_atoi(av[index + 1]);
		if (!((vm->log == CYCLE_LOG) || (vm->log == DEATH_LOG)))
			vm_error(vm, ARGS_ERROR);
	}
}

void		parse_visu(t_vm *vm, char **av, int index)
{
	if (cmp_visu(av[index]) == 1)
		if (!(vm->visu = ft_memalloc(sizeof(t_visu))))
			malloc_error(vm);
}

void		parse_number(t_vm *vm, char **av, int index)
{
	t_player	*new;
	int			ret_atoi;

	if (cmp_number(av[index]) == 1)
	{
		if (!av[index + 1] || !av[index + 2])
			vm_error(vm, ARGS_ERROR);
		if (check_is_digit_string(av[index + 1]) == 0)
			vm_error(vm, ARGS_ERROR);
		ret_atoi = ft_atoi(av[index + 1]);
		if (ret_atoi < 1 || ret_atoi > 4)
			vm_error(vm, ARGS_ERROR);
		new = create_new_player(vm);
		new->name = av[index + 2];
		new->number = ret_atoi;
		vm->nb_player++;
	}
}

t_player	*create_new_player(t_vm *vm)
{
	t_player *new;

	if (!(new = malloc(sizeof(t_player))))
		malloc_error(vm);
	ft_bzero(new, sizeof(t_player));
	new->next = vm->player;
	vm->player = new;
	return (new);
}
