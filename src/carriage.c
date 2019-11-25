/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:57:03 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 17:07:54 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_carriage	*ft_carriage_new(void)
{
	t_carriage	*new;

	if (!(new = ft_memalloc(sizeof(t_carriage))))
	{
		ft_putendl("Internal malloc error");
		exit(EXIT_FAILURE);
	}
	return (new);
}


void		ft_carriage_push_back(t_carriage **lst, t_carriage *new)
{
	t_carriage	*p;


	if (!lst ||  !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = *lst;
	while (p->next)
		p = p->next;
	p->next = new;
}

void		ft_carriage_free(t_carriage **lst)
{
	t_carriage 	*p;

	p = *lst;
	while (p)
	{
		(*lst) = (*lst)->next;
		free(p);
		p = (*lst);
	}
}
