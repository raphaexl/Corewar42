/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:27:16 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:27:18 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*to_find;
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	to_find = (char*)needle;
	str = (char*)haystack;
	if (to_find[0] == '\0')
		return (&str[i]);
	while (str[i] && len)
	{
		j = 0;
		while (to_find[j] == str[j + i] && to_find[j] && (i + j) < len)
			j++;
		if (to_find[j] == '\0' && i < len)
			return (&str[i]);
		i++;
	}
	return (0);
}
