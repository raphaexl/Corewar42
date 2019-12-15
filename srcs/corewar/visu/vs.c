/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 00:47:33 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/13 21:22:38 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void			fill_info(t_vm *vm)
{
	int			*clr;
	int			i;
	t_player	*tmp;

	clr = (int[]){0, 0, 0};
	attron(COLOR_PAIR(20));
	mvprintw(3, 202, "*RUNNING*");
	mvprintw(7, 202, "Cycle :");
	mvprintw(9, 202, "Processes :");
	i = 0;
	tmp = vm->player;
	while (i < vm->nb_player)
	{
		colors(clr, i + 1);
		mvprintw(11 + i * 4, 202, "Player -%d:", i + 1);
		attron(COLOR_PAIR(clr[2]));
		mvprintw(11 + i * 4, 213, "%s", tmp->exec->head.prog_name);
		attron(COLOR_PAIR(20));
		mvprintw(13 + i * 4, 204, "Last live :");
		i++;
		tmp = tmp->next;
	}
	fill_info2(i, vm);
}

void			vm_visuu(t_vm *vm, t_byte bytes[][64], int i)
{
	fill_arena(bytes, vm->memory, i);
	fill_info(vm);
	if (i == 0)
		fill_player_frst(bytes, vm->process, vm);
	else
		fill_player(bytes, vm->process);
	draw_arena(bytes, vm);
	print_speed(vm);
	refresh();
}

t_player		*player_pointer(t_vm *vm, int i)
{
	int			j;
	t_player	*tmp;

	tmp = vm->player;
	j = 0;
	while (j < i)
	{
		tmp = tmp->next;
		j++;
	}
	return (tmp);
}

void			vm_winner(t_vm *vm)
{
	int			*clr;
	int			key;
	t_player	*tmp;

	clr = (int[]){0, 0, 0};
	attron(COLOR_PAIR(20));
	mvprintw(40 + (vm->nb_player - 1) * 4, 202, "||  THE WINNER || ===>");
	mvprintw(42 + (vm->nb_player - 1) * 4, 202, "Press Q to close the window");
	if (!vm->winner)
		mvprintw(40 + (vm->nb_player - 1) * 4, 226, "No WINNER !!");
	else
	{
		vm->visu->wnr = vm->winner->number;
		tmp = player_pointer(vm, vm->visu->wnr - 1);
		colors(clr, vm->visu->wnr);
		attron(COLOR_PAIR(clr[2]));
		mvprintw(40 + (vm->nb_player - 1) * 4, 226, "%s",
				tmp->exec->head.prog_name);
	}
	key = getch();
	while (!(key == 'q'))
		key = getch();
}

void			vm_visu(t_vm *vm, t_byte bytes[][64])
{
	int		key;

	draw_border();
	vm_visuu(vm, bytes, vm->cycle);
	key = getch();
	if (vm->visu->end_game == 1)
		vm_winner(vm);
	if (key == ' ' || vm->visu->visu_event == 's')
	{
		attron(COLOR_PAIR(20));
		mvprintw(3, 202, "*PAUSE*   ");
		refresh();
		key = getch();
		while (!(key == ' ' || key == 's' || key == 'q'))
			key = getch();
		if (key == 'q' && (vm->visu->quit = TRUE))
		{
			vm->visu->end_game = 1;
			vm_winner(vm);
			return ;
		}
		mvprintw(3, 202, "*RUNNING*");
		refresh();
	}
	vm_visu_event(key, vm);
}
