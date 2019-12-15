/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 12:45:36 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/13 17:30:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

int		main(int ac, char **av)
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm));
	if (ac < 2 || ac > 16)
		vm_error(&vm, ARGS_ERROR);
	vm_init(&vm, ac, av);
	clash_of_champ(&vm);
	print_winner(&vm);
	vm_quit(&vm);
	return (0);
}
