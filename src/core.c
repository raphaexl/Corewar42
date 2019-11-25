/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:48:18 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/23 19:27:21 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

t_exec		*ft_read_code(const char *file_name)
{
	t_exec	*code;
	int		i;
	int		n;
	int		fd;
	
	n = 0;
	code = ft_memalloc(sizeof(*code));
	fd = open(file_name, O_RDONLY);
	if (fd < 0 || fd > 4096)
		return (NULL);
	if ((code->head.magic = ft_read_bytes(fd, 4)) != COREWAR_EXEC_MAGIC)
		return (NULL);
	i= -1;
	while (++i < PROG_NAME_LENGTH)
		code->head.prog_name[i] = ft_read_bytes(fd, 1);
	if (!(0 == ft_read_bytes(fd, 4)))
		return (NULL);
	if ((code->head.prog_size = ft_read_bytes(fd, 4)) > CHAMP_MAX_SIZE)
		return (NULL);
	
	i= -1;
	while (++i < COMMENT_LENGTH)
	 code->head.comment[i] = ft_read_bytes(fd, 1);

	if (!(0 == ft_read_bytes(fd, 4)))
		return (NULL);
	i= -1;
	code->code = ft_memalloc(sizeof(unsigned char) * code->head.prog_size);
	while (++i < (int )code->head.prog_size)
		code->code[i] = ft_read_bytes(fd, 1);
	if (!(i == (int)code->head.prog_size))
		return (NULL);
	close(fd);
	return (code);
}
