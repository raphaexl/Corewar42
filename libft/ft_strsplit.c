/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:27:36 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:27:38 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(char *s, char c)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_wlen(char *s, char c)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		return (len);
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char				**tmp;
	int					i;
	size_t				wcount;

	i = 0;
	wcount = ft_wcount((char *)s, c);
	if (!(tmp = (char **)malloc(sizeof(char *) * wcount + 1)))
		return (NULL);
	else
	{
		while (wcount)
		{
			while (*s == c && *s)
				s++;
			tmp[i] = ft_strsub(s, 0, ft_wlen((char *)s, c));
			while (*s != c && *s)
				s++;
			i++;
			wcount--;
		}
		tmp[i] = NULL;
	}
	return (tmp);
}
