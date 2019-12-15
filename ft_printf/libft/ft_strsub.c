/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:27:45 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:27:46 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*buff;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	if (!(buff = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (++i < len)
	{
		buff[i] = s[start];
		start++;
	}
	buff[i] = '\0';
	return (buff);
}
