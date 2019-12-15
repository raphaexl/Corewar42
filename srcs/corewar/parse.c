/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:58:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 16:41:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	parse(t_vm *vm)
{
	int	i;

	i = 1;
	while (vm->cmd_arg->av[i])
	{
		parse_dump(vm, vm->cmd_arg->av, i);
		parse_number(vm, vm->cmd_arg->av, i);
		parse_visu(vm, vm->cmd_arg->av, i);
		parse_log(vm, vm->cmd_arg->av, i);
		parse_other_think(vm, vm->cmd_arg->av, i);
		i++;
	}
	parse_player(vm);
	check_player(vm);
	pos_pc_player(vm);
	add_process(vm);
	parse_read(vm);
}

int		corewar_header(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len < 5)
		return (0);
	return (!ft_strcmp(&s[len - 4], ".cor"));
}

int		corewar_number(char **av, int index)
{
	if (!check_is_digit_string(av[index]))
		return (0);
	if (index < 1)
		return (0);
	if (cmp_number(av[index - 1]) || cmp_dump(av[index - 1])
			|| cmp_log(av[index - 1]))
		return (1);
	return (0);
}

void	parse_other_think(t_vm *vm, char **av, int index)
{
	if (!cmp_dump(av[index]) && !(cmp_number(av[index])) && \
			!corewar_header(av[index]) && !corewar_number(av, index) \
			&& !cmp_visu(av[index]) && !cmp_log(av[index]))
		vm_error(vm, ARGS_ERROR);
}
