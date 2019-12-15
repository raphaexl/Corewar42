/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztatbat <ztatbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:22:21 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/13 14:03:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

int		in_pross(t_process *pross)
{
	int			i;
	t_process	*tmp;

	i = 0;
	tmp = pross;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	live_breakdown(int **tbl, t_vm *vm)
{
	int			i;
	t_player	*tmp;

	tbl[0][vm->nb_player] = 0;
	i = 0;
	while (i < vm->nb_player)
	{
		tmp = player_pointer(vm, i);
		tbl[0][vm->nb_player] += tmp->live;
		i++;
	}
	i = 0;
	while (i < vm->nb_player && tbl[0][vm->nb_player])
	{
		tmp = player_pointer(vm, i);
		tbl[0][i] = ((tmp->live * 100) / tbl[0][vm->nb_player]);
		tbl[0][i] = (tbl[0][i] * 72) / 100;
		i++;
	}
}

void	draw_breakdown(int n, t_vm *vm, int where, int player)
{
	int		i;
	int		*clr;

	i = 0;
	clr = (int[]){0, 0, 0};
	while (i < n)
	{
		colors(clr, player);
		attron(COLOR_PAIR(clr[2]));
		mvprintw(18 + (vm->nb_player - 1) * 4, 205 + where + i, "-");
		i++;
	}
}

void	fill_game2(t_vm *vm, int *tbl)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(17));
	mvprintw(18 + (vm->nb_player - 1) * 4, 204, "[");
	tbl[vm->nb_player] = 0;
	while (i < vm->nb_player)
	{
		draw_breakdown(tbl[i], vm, tbl[vm->nb_player], i + 1);
		tbl[vm->nb_player] += tbl[i];
		i++;
	}
	attron(COLOR_PAIR(17));
	mvprintw(18 + (vm->nb_player - 1) * 4, 205 + tbl[vm->nb_player], "]");
	attron(COLOR_PAIR(16));
	mvprintw(18 + (vm->nb_player - 1) * 4, 206 + tbl[vm->nb_player], "  ");
}

void	fill_game(t_vm *vm)
{
	int			i;
	int			*tbl;
	t_player	*tmp;

	tbl = malloc(sizeof(int) * (vm->nb_player + 1));
	live_breakdown(&tbl, vm);
	i = 0;
	attron(COLOR_PAIR(20));
	mvprintw(7, 210, "%d", vm->cycle);
	mvprintw(9, 214, "%d", in_pross(vm->process));
	while (i < vm->nb_player)
	{
		tmp = player_pointer(vm, i);
		mvprintw(13 + i * 4, 250, "%d", tmp->live);
		i++;
	}
	mvprintw(20 + (i - 1) * 4, 218, "%5d", vm->cycle_to_die);
	attron(COLOR_PAIR(17));
	if (tbl[vm->nb_player] == 0)
		mvprintw(18 + (i - 1) * 4, 224, "[NO DATA FOR NOW]");
	else
		fill_game2(vm, tbl);
	free(tbl);
}
