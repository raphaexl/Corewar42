/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:18:14 by kchahid           #+#    #+#             */
/*   Updated: 2018/10/26 15:18:16 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_negative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		signe;
	char	*buff;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	signe = 0;
	is_negative(&n, &signe);
	while (tmpn /= 10)
		len++;
	len += signe;
	if ((buff = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	buff[--len] = '\0';
	while (len--)
	{
		buff[len] = (n % 10 + '0');
		n /= 10;
	}
	if (signe)
		buff[0] = '-';
	return (buff);
}
