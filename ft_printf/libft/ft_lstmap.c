/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:19:15 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:19:19 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	list = f(lst);
	new = list;
	lst = lst->next;
	while (lst != NULL)
	{
		list->next = f(lst);
		lst = lst->next;
		list = list->next;
	}
	return (new);
}
