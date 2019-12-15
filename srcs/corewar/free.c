/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:06:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 17:40:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	process_clean(t_process **process)
{
	t_process *p;

	if (!process || !*process)
		return ;
	p = (*process);
	while (p)
	{
		(*process) = (*process)->next;
		free(p);
		p = (*process);
	}
}

void	player_clean(t_player **players)
{
	t_player *p;

	if (!players || !*players)
		return ;
	p = (*players);
	while (p)
	{
		(*players) = (*players)->next;
		if (p->exec)
		{
			if (p->exec->code)
				free(p->exec->code);
			free(p->exec);
		}
		free(p);
		p = (*players);
	}
}
