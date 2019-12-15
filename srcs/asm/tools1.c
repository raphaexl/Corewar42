/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 23:57:08 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 17:39:01 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	skip_spaces(char **str)
{
	while ((str[0][0] == ' ' || str[0][0] == '\t'))
		str[0]++;
}

int		my_memdel(void **ap)
{
	if (ap == NULL)
		return (1);
	free(*ap);
	*ap = NULL;
	return (1);
}

void	swappedbytes(void *src, void *dst, int size)
{
	int i;
	int j;

	i = 0;
	j = size - 1;
	while (i < size)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[j];
		j--;
		i++;
	}
}

int		nbbytes(int index, t_inst *inst, int wanted)
{
	int counter;

	counter = 0;
	if (wanted > index)
	{
		while (index != wanted)
		{
			counter += inst[index].inst_bytes;
			index++;
		}
	}
	else
	{
		while (index > wanted)
		{
			counter -= inst[index - 1].inst_bytes;
			index--;
		}
	}
	return (counter);
}
