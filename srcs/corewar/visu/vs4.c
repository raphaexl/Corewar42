/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:24:02 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/12 17:24:46 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void	refresh_sleep(t_vm *vm)
{
	fill_game(vm);
	refresh();
	usleep(vm->visu->visu_spd);
}

void	draw_arena(t_byte arena[][64], t_vm *vm)
{
	int		i;
	int		j;
	int		*clr;

	i = -1;
	clr = (int[]){0, 0, 0};
	while (++i < 64 && (j = -1))
	{
		while (++j < 64)
		{
			colors(clr, arena[i][j].player);
			attron(COLOR_PAIR(clr[0]));
			if (arena[i][j].status >= 1)
				attron(COLOR_PAIR(clr[2]));
			else if (arena[i][j].cp == 1)
				attron(COLOR_PAIR(clr[1]));
			arena[i][j].cp = 0;
			if (arena[i][j].status > 0)
				arena[i][j].status--;
			mvprintw(i + 2, j * 2 + j + 3, arena[i][j].content);
		}
	}
	refresh_sleep(vm);
}

void	fill_arena(t_byte arena[][64], unsigned char arena_un[4 * 1024], int a)
{
	int		i;
	int		j;
	int		k;
	char	*last;

	i = -1;
	k = 0;
	while (++i < 64 && (j = -1))
	{
		while (++j < 64)
		{
			last = ft_itoa_base_u(arena_un[k + j], 16, 0);
			if (ft_strlen(last) != 2)
				last = ft_strjoin("0", last);
			if (ft_strcmp(last, arena[i][j].content))
			{
				arena[i][j].content[0] = last[0];
				arena[i][j].content[1] = last[1];
				arena[i][j].status = (a == 0) ? 0 : 100;
			}
			free(last);
		}
		k = k + 64;
	}
}

void	get_coor(int **tbl, int pc)
{
	tbl[0][0] = pc / 64;
	tbl[0][0] = tbl[0][0] % 64;
	tbl[0][1] = pc % 64;
}

int		null_bytes(t_byte arena[][64], int *tbl)
{
	int	i;

	i = 0;
	attron(COLOR_PAIR(2));
	mvprintw(0, 0, "null_bytes                                      ");
	while (i < 4)
	{
		if (!ft_strcmp(arena[tbl[0]][tbl[1]].content, "00"))
			return (0);
		if (tbl[1] < 63)
			tbl[1]++;
		else
		{
			tbl[0] = (tbl[0] + 1) % 64;
			tbl[1] = 0;
		}
		i++;
	}
	return (1);
}
