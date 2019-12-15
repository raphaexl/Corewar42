/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add_sub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 12:56:15 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/10 23:20:22 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

/*
** op_add                     add r1,r4,r15 (0x04)
** Cette instruction prend 3 registres en paramètre.
** additionne le contenu des 2 premiers et met le résultat dans le troisième.
** ************************************************************************** *
** HEXDUMP 04 54 01 04 0F         | VM_MEMORY  4 84 1 4 15
** 04 == 4  == OP_CODE            | 54 ? 84 => T_REG == 01 [we have 3 T_REG]
** 54 == 84 == TYPE_ARGUMENT      | 01 01 01 + 00 in the right [always]
** 01 == 1  == r1                 | BINARY  == 01010100
** 04 == 4  == r2                 | DECIMAL == 84
** 0F == 15 == r15                | HEX     == 54
** ************************************************************************** *
** TYPE_ARGUMENT CALC -> 01 01 01 00 | 01 01 00 00 | 01 00 00 00 | T_REG == 1
** OP_ADD CALC        -> registre 15 = registre 1 + registre 4
** ************************************************************************** *
** ************************************************************************** *
** op_sub                     sub r5,r4,r9 (0x05)  05 54 05 04 09
** Cette instruction prend 3 registres en paramètre.
** soustrait le contenu des 2 premiers et met le résultat dans le troisième.
** op_add == op_sub [ a la place de + on trouve - dans calc des registres ]
** ************************************************************************** *
*/

#define REG_1 (process->reg[arg_1 - 1])
#define REG_2 (process->reg[arg_2 - 1])
#define REG_3 (process->reg[arg_3 - 1])

static int		check_reg(char arg_1, char arg_2, char arg_3)
{
	if ((arg_1 > 0 && arg_1 < 17) && (arg_2 > 0 && arg_2 < 17) &&
			(arg_3 > 0 && arg_3 < 17))
		return (1);
	return (0);
}

static void		carry(t_process *process, char arg_3)
{
	if (REG_3 == 0)
		process->carry = 1;
	else
		process->carry = 0;
}

void			op_add_sub(t_vm *vm, t_process *process, int index)
{
	unsigned char	arg_type;
	char			arg_1;
	char			arg_2;
	char			arg_3;

	arg_type = vm->memory[(process->pc + 1) % MEM_SIZE];
	type_argument(process, arg_type, 3);
	if (arg_is_valid(process, 3) == 1 && (process->pc_step += 5))
	{
		arg_1 = vm->memory[(process->pc + 2) % MEM_SIZE];
		arg_2 = vm->memory[(process->pc + 3) % MEM_SIZE];
		arg_3 = vm->memory[(process->pc + 4) % MEM_SIZE];
		if (check_reg(arg_1, arg_2, arg_3) == 1)
		{
			if (index == 1)
				REG_3 = REG_1 + REG_2;
			else if (index == 2)
				REG_3 = REG_1 - REG_2;
			carry(process, arg_3);
		}
	}
	else
		process->pc_step = skip_byte(arg_type, 3, 4);
}
