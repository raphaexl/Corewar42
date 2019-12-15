/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:21:09 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/13 14:02:53 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void		zero(int a, int x, int y)
{
	attron(COLOR_PAIR(2));
	mvprintw(0, 0, "zero                                      ");
	while (a)
	{
		attron(COLOR_PAIR(16));
		attron(COLOR_PAIR((64 - a) % 15));
		y++;
		mvprintw(x, y, "00");
		y = y + 2;
		a--;
		refresh();
	}
}

void		draw_border(void)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(13));
	while (i++ <= 68)
		mvprintw(i, 0, " ");
	i = 0;
	while (i++ <= 68)
		mvprintw(i, 196, " ");
	i = 0;
	while (i++ <= 68)
		mvprintw(i, 200, " ");
	i = 0;
	while (i++ <= 68)
		mvprintw(i, 280, " ");
	i = -1;
	while (i++ <= 195 && !mvprintw(69, i, " "))
		mvprintw(0, i, " ");
	i = 199;
	while (i++ <= 279)
	{
		mvprintw(0, i, " ");
		mvprintw(69, i, " ");
	}
}

void		colors2(int *tbl, int player)
{
	if (player == 4)
	{
		tbl[0] = 10;
		tbl[1] = 11;
		tbl[2] = 12;
	}
	else if (player == 3)
	{
		tbl[0] = 7;
		tbl[1] = 8;
		tbl[2] = 9;
	}
	else
	{
		tbl[0] = 17;
		tbl[1] = 14;
		tbl[2] = 15;
	}
}

void		colors(int *tbl, int player)
{
	if (player == 4 || player == 0 || player == 3)
		colors2(tbl, player);
	if (player == 1)
	{
		tbl[0] = 1;
		tbl[1] = 2;
		tbl[2] = 3;
	}
	else if (player == 2)
	{
		tbl[0] = 4;
		tbl[1] = 5;
		tbl[2] = 6;
	}
}

void		init_clr(void)
{
	init_pair(1, 2, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, 2);
	init_pair(3, 10, COLOR_BLACK);
	init_pair(4, 21, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, 21);
	init_pair(6, 33, COLOR_BLACK);
	init_pair(7, 88, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, 88);
	init_pair(9, 160, COLOR_BLACK);
	init_pair(10, 129, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, 129);
	init_pair(12, 201, COLOR_BLACK);
	init_pair(13, COLOR_BLACK, 244);
	init_pair(17, 244, COLOR_BLACK);
	init_pair(14, COLOR_BLACK, 247);
	init_pair(15, COLOR_BLACK, 255);
	init_pair(16, COLOR_BLACK, COLOR_BLACK);
	init_pair(20, 255, COLOR_BLACK);
}
