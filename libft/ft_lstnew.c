/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:19:46 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:19:48 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*tmp;

	list = (t_list*)malloc(sizeof(t_list));
	if (list != NULL)
	{
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			tmp = ft_memalloc(content_size);
			ft_memcpy(tmp, content, content_size);
			list->content = tmp;
			list->content_size = content_size;
		}
		list->next = NULL;
	}
	else
		return (NULL);
	return (list);
}
