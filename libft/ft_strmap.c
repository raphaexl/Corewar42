/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:26:16 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:26:18 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	dst = (char *)malloc(sizeof(*dst) * (ft_strlen(s) + 1));
	if (dst)
	{
		while (s[i] != '\0')
		{
			dst[i] = (*f)(s[i]);
			i++;
		}
		dst[i] = '\0';
	}
	else
		return (0);
	return (dst);
}
