/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:22:01 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:22:02 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*str;

	dest = (char *)dst;
	str = (char *)src;
	i = 0;
	if (dest > str)
		while (++i <= len)
			dest[len - i] = str[len - i];
	else
		while (i < len)
		{
			dest[i] = str[i];
			i++;
		}
	return (dst);
}
