/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:25:50 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:25:52 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*buff;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	buff = (char *)malloc(sizeof(*buff) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!buff)
		return (NULL);
	i = -1;
	while (s1[++i])
		buff[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		buff[i] = s2[j];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
