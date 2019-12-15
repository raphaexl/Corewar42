/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 22:41:16 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 12:31:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

int			cmp_dump(char *av)
{
	if (!ft_strcmp(av, "-d") || !ft_strcmp(av, "-dump"))
		return (1);
	return (0);
}

int			cmp_log(char *av)
{
	if (!ft_strcmp(av, "-l") || !ft_strcmp(av, "-log"))
		return (1);
	return (0);
}

int			cmp_visu(char *av)
{
	if (!ft_strcmp(av, "-v") || !ft_strcmp(av, "-visu"))
		return (1);
	return (0);
}

int			cmp_number(char *av)
{
	if (!ft_strcmp(av, "-n") || !ft_strcmp(av, "-number"))
		return (1);
	return (0);
}

int			cmp_player_cor(char *s)
{
	int		len;

	len = ft_strlen(s);
	if (len < 5)
		return (0);
	return (!ft_strcmp(&s[len - 4], ".cor"));
}
