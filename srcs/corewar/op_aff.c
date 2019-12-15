/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:28:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/10 23:21:31 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_aff                    aff r8 (0x10)
** Cette op est suivi d’un octet de paramétrage pour décrire les paramètres.
** elle prend un registre et affiche le char dont est présent dans le reg.
** ************************************************************************** *
** HEXDUMP 10 40 08               | VM_MEMORY  16 64 8
** 10 == 16  == OP_CODE           | 40 ? 64 => T_REG == 01 [we have 1 T_REG]
** 40 == 64 == TYPE_ARGUMENT      | 01 + 00 00 00
** 08 == 8  == r8                 | BINARY  == 01 00 00 00
**                                | DECIMAL == 64
**                                | HEX     == 40
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 01 00 00 00 << 6 == 00 00 00 01 | T_REG == 1
** OP_AFF CALC        -> ft_putchar(reg[arg_1])
** (un modulo 256 est applique au code ascii, ?
** le caractère est affiché sur la sortie standard). ?
*/

void	op_aff(t_vm *vm, t_process *process)
{
	int8_t	arg_type;
	char	arg_1;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	if (arg_type == 64 && (process->pc_step = 3))
	{
		arg_1 = vm->memory[(process->pc + 2) % MEM_SIZE];
		if (arg_1 > 0 && arg_1 < 17)
			ft_putchar((char)process->reg[arg_1 - 1]);
	}
	else
		process->pc_step = skip_byte(arg_type, 1, 4);
}
