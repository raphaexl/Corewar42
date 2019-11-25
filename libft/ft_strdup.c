/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:25:19 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:25:21 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *buff;

	buff = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!buff)
	{
		buff = NULL;
		return (buff);
	}
	ft_strcpy(buff, s1);
	return (buff);
}
