/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:27:26 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:27:27 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*buff;

	buff = (char *)s;
	i = ft_strlen(s) + 1;
	while (i-- > 0)
		if (s[i] == c)
			return (&buff[i]);
	return (0);
}
