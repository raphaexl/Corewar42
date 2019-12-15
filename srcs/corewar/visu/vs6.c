/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztatbat <ztatbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:29:26 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/12 17:27:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void	fill_player_frst(t_byte bytes[][64], t_process *pross, t_vm *vm)
{
	t_process	*tmp;
	int			*tbl;
	int			i;
	t_player	*tmp_pl;

	i = 0;
	tmp = pross;
	tbl = (int[]){0, 0};
	while (tmp)
	{
		tmp_pl = player_pointer(vm, tmp->player_id - 1);
		get_coor(&tbl, tmp->pc);
		fill_one(tbl, bytes, tmp_pl\
				, tmp->player_id);
		tmp = tmp->next;
		i++;
	}
}

void	print_speed(t_vm *vm)
{
	int	i;
	int	j;

	j = 0;
	i = 12 + (30000 - vm->visu->visu_spd) / 3000;
	attron(COLOR_PAIR(16));
	mvprintw(28 + (vm->nb_player - 1) * 4, 210,\
			"                                              ");
	while (j <= i)
	{
		attron(COLOR_PAIR(13));
		mvprintw(28 + (vm->nb_player - 1) * 4, 210 + j * 2, " ");
		attron(COLOR_PAIR(16));
		mvprintw(28 + (vm->nb_player - 1) * 4, 210 + j * 2 + 1, " ");
		j++;
	}
}

void	fill_info2(int i, t_vm *vm)
{
	mvprintw(20 + (i - 1) * 4, 202, "CYCLE_TO_DIE :");
	mvprintw(22 + (i - 1) * 4, 202, "CYCLE_DELTA : 50");
	mvprintw(24 + (i - 1) * 4, 202, "NBR_LIVE : 21");
	mvprintw(26 + (i - 1) * 4, 202, "MAX_CHECKS : 10");
	mvprintw(28 + (i - 1) * 4, 202, "SPEED :");
	mvprintw(30 + (i - 1) * 4, 202, "     \
			||  CONTROL  ||");
	mvprintw(32 + (i - 1) * 4, 202, "Pause / Run             : Space");
	mvprintw(34 + (i - 1) * 4, 202, "To the next cycle       : s");
	mvprintw(36 + (i - 1) * 4, 202, "Speed control , up/down : u / d");
	print_speed(vm);
}

void	init_vs(t_vm *vm)
{
	int	i;
	int	j;

	initscr();
	curs_set(FALSE);
	use_default_colors();
	start_color();
	init_clr();
	noecho();
	cbreak();
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	draw_border();
	getch();
	i = -1;
	while (++i < 64 && (j = -1))
		while (++j < 64)
			ft_bzero(&vm->visu->bytes[i][j], sizeof(t_byte));
	vm->visu->visu_spd = 9000;
	vm->visu->visu_event = 'n';
	vm->visu->quit = FALSE;
}
