/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:21:36 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:21:37 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dest;
	char			*str;

	dest = (char *)dst;
	str = (char *)src;
	i = -1;
	while (++i < n)
		dest[i] = str[i];
	return (dst);
}
