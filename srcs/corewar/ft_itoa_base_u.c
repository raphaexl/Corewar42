/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:26:51 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/11 00:06:31 by kchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

char	*ft_itoa_base_u(unsigned long long int value, int base, int upper)
{
	char					*str;
	int						size;
	char					*tab;
	unsigned long long int	tmp;

	size = 0;
	if (upper)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (0);
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + 1;
	str = (char *)malloc(sizeof(char) * size + 1);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[(value % base)];
		size--;
		value /= base;
	}
	return (str);
}
