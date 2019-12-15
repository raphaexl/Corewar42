/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:30:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 13:16:56 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** 0x0B (sti)	sti r2,%4,%5 copie REG_SIZE octets de r2 a l’adresse (4 + 5).
** Les paramètres 2 et 3 sont des index.
** Si les param 2 ou 3 sont des reg, on utilisera leur contenu comme un index.
*/

#define REG process->reg[arg_1 - 1]

static void	write_op(t_vm *vm, t_process *process, int value, int pc_step)
{
	int		i;
	char	*s;

	i = -1;
	s = (char *)&value;
	if (pc_step < 0)
		pc_step += 4096;
	while (++i < 4)
		vm->memory[(process->pc + pc_step + i) % MEM_SIZE] = s[3 - i];
}

static int	check_param(char arg_1, int arg_2, int arg_3)
{
	if (arg_1 > 0 && arg_1 < 17 && arg_2 == 0 && arg_3 == 0)
		return (1);
	return (0);
}

static void	op_sti_2(t_vm *vm, t_process *process, t_arg *arg_2, t_arg *arg_3)
{
	ft_bzero(arg_2, sizeof(t_arg));
	ft_bzero(arg_3, sizeof(t_arg));
	arg_2->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	arg_3->dir_size = g_op_tab[vm->memory[process->pc]].size_dir;
	value_with_modulo(vm, process, arg_2, process->args[1]);
	process->pc_step += step_add(process->args[1], arg_2->dir_size);
	value_with_modulo(vm, process, arg_3, process->args[2]);
	process->pc_step += step_add(process->args[2], arg_3->dir_size);
}

void		op_sti(t_vm *vm, t_process *process)
{
	unsigned char	arg_type;
	char			arg_1;
	t_arg			arg_2;
	t_arg			arg_3;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 3);
	if (arg_is_valid(process, 3) == 1 && (process->pc_step += 2))
	{
		arg_1 = vm->memory[(process->pc + process->pc_step) % MEM_SIZE];
		process->pc_step += 1;
		op_sti_2(vm, process, &arg_2, &arg_3);
		if (check_param(arg_1, arg_2.error, arg_3.error) == 1)
		{
			process->count_st_sti = int_modulo(arg_2.value + arg_3.value);
			write_op(vm, process, REG, process->count_st_sti);
		}
	}
	else
		process->pc_step = skip_byte(arg_type, 3, 2);
}
