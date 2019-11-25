/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:00:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 17:05:05 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

unsigned char	ft_get_memory_byte(unsigned char memory[MEM_SIZE], int loc)
{
	return (memory[loc %= MEM_SIZE]);
}
