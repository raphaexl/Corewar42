/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:27:26 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/11 18:36:36 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		ft_champion_name(char *s)
{
	int		i;

	i = ft_strlen(s) - 1;
	if (i > 3 && s[i - 3] == '.' && s[i - 2] == 'c' && s[i - 1] == 'o' && s[i] == 'r')
		return (1);
	return (0);
}

int		ft_nonassigned(int tab[8])
{
	int		i;
	int		j;
	int		found;
	int		n;

	i = -1;
	n = 0;
	j = 0;
	while(++i < 4)
	{
		++n;
		j = -1;
		found = 0;
		while (++j < 4)
		{
			if (tab[j + 4] == n)
			{
				found = 1;
				break ;
			}
		}
		if (found)
			continue ;
		else
			break ;
	}
	return (n);
}
