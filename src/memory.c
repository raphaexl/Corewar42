/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:31:23 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

unsigned char	ft_get_memory_byte(unsigned char memory[MEM_SIZE], int loc)
{
	return (memory[loc % MEM_SIZE]);
}

unsigned int	ft_read_mem_value(unsigned char memory[MEM_SIZE], int loc, size_t size)
{
	char			*buff;
	size_t			i;
	unsigned int	value;
	
	buff = ft_memalloc(size * sizeof(char));
	i = 0;
	value = 0;
	while (i < size)
	{
		buff[i] = ft_get_memory_byte(memory, i + loc);
		i++;
	}
	value = ft_atoi_base(buff, 16);
	free(buff);
	return (value);
}
