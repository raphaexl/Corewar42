/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:50:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/11 20:56:56 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

int		print_exec_code_error(int err_code)
{
	if (err_code == HM_ERROR)
		ft_putendl("Error : exec code -> head magic error");
	else if (err_code == NLB_ERROR)
		ft_putendl("Error : exec code -> null byte error");
	else if (err_code == PSIZE_ERROR)
		ft_putendl("Error : exec code -> prog size error");
	return (0);
}

void	print_contestants(t_vm *vm)
{
	t_player	*p;

	p = vm->player;
	ft_printf("Introducing contestants...\n");
	while (p)
	{
		printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		p->number, p->exec->head.prog_size,
		p->exec->head.prog_name, p->exec->head.comment);
		p = p->next;
	}
}

void	print_winner(t_vm *vm)
{
	if (vm->winner && !vm->visu)
		ft_printf("Contestant %d, \"%s\", has won !\n", vm->winner->number,
				vm->winner->exec->head.prog_name);
}

int		print_corewar_usage(void)
{
	ft_putstr("Usage: ./corewar [(-dump|-d) ");
	ft_putendl("<num> -l <num>] [-v] [-n <num>] <champion.cor> <...>");
	ft_putstr("	-dump <num> : Dump memory ");
	ft_putendl("(32 octets per line) after <num> cycles and exit");
	ft_putstr("	-d    <num> : Dump memory ");
	ft_putendl("(64 octets per line) after <num> cycles and exit");
	ft_putendl("	-l    <num> : Log levels");
	ft_putendl("					1  : Show cycles");
	ft_putendl("					2  : Show deaths");
	ft_putendl("	-v          : Run visualizer");
	ft_putendl("	-n    <num> : Set <num> of the next player");
	return (0);
}
