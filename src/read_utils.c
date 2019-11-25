/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:36:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/23 17:25:30 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

unsigned int	ft_unsigned_int(unsigned char *bytes)
{
	int				i;
	unsigned int	value;

	i = -1;
	value = 0;
	while (++i < 4)
		value = (value << 8) | (bytes[i]);
	return (value);
}

void			ft_write_bytes(unsigned char *buff, unsigned int code)
{
	buff[0] = code & 0xff;
	buff[1] = (code >> 8) & 0xFF;
}

unsigned int	ft_read_bytes(int fd, size_t size)
{
	unsigned char	buff[size];
	unsigned int	value;
	size_t			i;
	size_t			n;

	n = read(fd, buff, size);
	i = 0;
	value = buff[0];
	while (i++ < n - 1)
	{
		value <<= 8;
		value |= buff[i];
	}
	return (value);
}
