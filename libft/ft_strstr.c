/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:29:33 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:29:34 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*to_find;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	to_find = (char*)needle;
	str = (char*)haystack;
	if (!to_find[0])
		return (&str[i]);
	while (str[i])
	{
		while (to_find[j] == str[j + i] && to_find[j])
			j++;
		if (!to_find[j])
			return (&str[i]);
		j = 0;
		i++;
	}
	return (0);
}
