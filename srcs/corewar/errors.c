/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:01:16 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 19:42:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	malloc_error(t_vm *vm)
{
	ft_printf("Internal malloc error\n");
	vm_quit(vm);
}

void	vm_error(t_vm *vm, int err_code)
{
	if (err_code == ARGS_ERROR)
		print_corewar_usage();
	else if (err_code == FD_ERROR)
		ft_putendl("Bad file\n");
	else if (err_code > -9 && err_code < -5)
		print_exec_code_error(err_code);
	vm_quit(vm);
}
