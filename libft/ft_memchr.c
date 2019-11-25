/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:20:18 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:20:20 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	buff = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (buff[i] == (unsigned char)c)
			return ((void *)buff + i);
		i++;
	}
	return (NULL);
}
