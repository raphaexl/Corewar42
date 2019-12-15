/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_libc_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 13:10:23 by kchahid           #+#    #+#             */
/*   Updated: 2019/07/09 13:11:35 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = ft_strnew(n);
	while (s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

char	*ft_strndup_r(const char *s1, size_t n, int move)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = ft_strnew(n);
	while (i < n && s1)
	{
		s2[i] = s1[move];
		i++;
		move++;
	}
	return (s2);
}

char	*ft_strrev(char *str)
{
	int					i;
	int					j;
	unsigned char		a;
	unsigned			len;

	i = 0;
	len = ft_strlen(str);
	j = len - 1;
	while (i < j)
	{
		a = str[i];
		str[i] = str[j];
		str[j] = a;
		i++;
		j--;
	}
	return (str);
}
