/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:20:07 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:20:09 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*dest;
	char	*str;

	dest = (char *)dst;
	str = (char *)src;
	i = 0;
	while (n > 0)
	{
		dest[i] = str[i];
		if (str[i] == (char)c)
			return (dest + i + 1);
		i++;
		n--;
	}
	return (NULL);
}
