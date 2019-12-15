/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztatbat <ztatbat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:25:05 by ztatbat           #+#    #+#             */
/*   Updated: 2019/12/12 17:24:54 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/vm.h"

void	fill_one(int *tbl, t_byte bytes[][64], t_player *player, int pl)
{
	unsigned int	i;

	i = 0;
	while (i < player->exec->head.prog_size)
	{
		bytes[tbl[0]][tbl[1]].player = pl;
		if (tbl[1] < 63)
			tbl[1]++;
		else
		{
			tbl[1] = 0;
			tbl[0]++;
		}
		i++;
	}
}

int		null_byte(t_byte arena[][64], int a, int b)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_strcmp(arena[a][b].content, "00"))
			return (0);
		if (b < 63)
			b++;
		else
		{
			a = (a + 1) % 64;
			b = 0;
		}
		i++;
	}
	return (1);
}

void	put_playeer(t_byte arena[][64], t_process *pross, int *tbl)
{
	int i;

	i = 0;
	while (i < 4)
	{
		arena[tbl[0]][tbl[1]].player = pross->player_id;
		arena[tbl[0]][tbl[1]].status = 200;
		if (tbl[1] < 63)
			tbl[1]++;
		else
		{
			tbl[0] = (tbl[0] + 1) % 64;
			tbl[1] = 0;
		}
		i++;
	}
}

void	put_player(int *tbl, t_byte arena[][64], t_process *pross)
{
	int pc;

	arena[tbl[0]][tbl[1]].cp = 1;
	if ((pross->op_code == 3 || pross->op_code == 11) && (pross->op_code | 48))
	{
		if (pross->op_code == 3)
			pc = pross->pc + pross->count_st_sti;
		else
			pc = pross->pc + pross->count_st_sti;
		if (pc > 5)
		{
			pc = pc - 5;
			pc = pc % 4096;
		}
		else
		{
			pc = pc % 4096;
			pc = 4096 - (5 - pc);
		}
		get_coor(&tbl, pc);
		if (!null_byte(arena, tbl[0], tbl[1]))
			put_playeer(arena, pross, tbl);
	}
}

void	fill_player(t_byte arena[][64], t_process *pross)
{
	t_process	*tmp;
	int			*tbl;
	int			i;

	tbl = (int[]){0, 0};
	tmp = pross;
	i = 0;
	while (tmp)
	{
		get_coor(&tbl, tmp->pc % 4096);
		put_player(tbl, arena, tmp);
		tmp = tmp->next;
		i++;
	}
}
