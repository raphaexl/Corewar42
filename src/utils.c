/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:54:13 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 21:36:19 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/corewar.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\f' || c == '\v');
}

static int	ft_base_16(unsigned char ch, unsigned int base)
{
	return ((ch >= '0' && ch <= '9')
	   	|| (ch >= 'a' && (ch <= (unsigned char)('a' + (base - 10)))) ||
		(ch >= 'A' && (ch <= (unsigned char)('A' + (base - 10)))));
}

unsigned int	ft_atoi_base(const char *nbr, unsigned int base)
{
	unsigned int	nb;
	int				i;

	if (base < 1 || base > 16)
		return (0);
	nb = 0;
	while (*nbr && ft_is_space(*nbr))
		nbr++;
	i = -1;
	if (*nbr && (*nbr == '+' || *nbr == '-'))
		i++;
	while (nbr[++i])
	{
		if (base < 11)
		{
			if ((nbr[i] >= '0') && (nbr[i] <= (unsigned char)('0' + (base - 1))))
			{
				nb += (nbr[i] - '0');
				if (nbr[i + 1] && (nbr[i + 1] >= '0') && (nbr[i + 1] <= (unsigned char)('0' + (base - 1))))
					nb *= base;
			}
			else
				break ;
		}
		else
		{
			if (ft_base_16(nbr[i], base))
			{
				if (nbr[i] >= '0' && nbr[i] <= '9')
					nb += (nbr[i] - '0');
				else if (nbr[i] >= 'a' && (nbr[i] <= (unsigned char)('a' + (base - 10))))
					nb += (nbr[i] - 'a' + 10);
				else if (nbr[i] >= 'A' && (nbr[i] <= (unsigned char)('A' + (base - 10))))
					nb += (nbr[i] - 'A' + 10);
				if (ft_base_16(nbr[i + 1], base))
					nb *= base;
			}
			else
				break ;
		}
	}
	if (nbr[0] == '-')
		return (-nb);
	return (nb);
}
