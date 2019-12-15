/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:26:00 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:26:01 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		cmp;
	size_t		i;
	size_t		j;

	cmp = 0;
	i = ft_strlen(dst);
	cmp = ft_strlen(src);
	if (size == 0)
		return (cmp);
	if (i > size)
		cmp += size;
	else
		cmp += i;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (cmp);
}
