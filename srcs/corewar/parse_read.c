/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 19:32:55 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/13 16:38:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/vm.h"

void	parse_read(t_vm *vm)
{
	t_player *player;

	player = vm->player;
	while (player)
	{
		player->exec = read_code(vm, player->name);
		player = player->next;
	}
}

t_exec	*read_code(t_vm *vm, char *file_name)
{
	t_exec	*code;
	int		i;
	int		fd;

	i = -1;
	if (!(code = ft_memalloc(sizeof(t_exec))))
		malloc_error(vm);
	if ((fd = open(file_name, O_RDONLY)) && (fd < 0 || fd > 4096))
		vm_error(vm, FD_ERROR);
	if ((code->head.magic = read_byte(fd, 4)) != COREWAR_EXEC_MAGIC)
		vm_error(vm, HM_ERROR);
	while (++i < PROG_NAME_LENGTH)
		code->head.prog_name[i] = read_byte(fd, 1);
	if (!(0 == read_byte(fd, 4)))
		vm_error(vm, NLB_ERROR);
	if ((code->head.prog_size = read_byte(fd, 4)) > CHAMP_MAX_SIZE)
		vm_error(vm, PSIZE_ERROR);
	read_code_2(vm, code, fd);
	close(fd);
	return (code);
}

void	read_code_2(t_vm *vm, t_exec *code, int fd)
{
	int	i;

	i = -1;
	while (++i < COMMENT_LENGTH)
		code->head.comment[i] = read_byte(fd, 1);
	if (!(0 == read_byte(fd, 4)))
		vm_error(vm, NLB_ERROR);
	i = -1;
	code->code = ft_memalloc(sizeof(unsigned char) * code->head.prog_size);
	if (!(code->code))
		malloc_error(vm);
	while (++i < (int)code->head.prog_size)
		code->code[i] = read_byte(fd, 1);
	if (!(i == (int)code->head.prog_size))
		vm_error(vm, PSIZE_ERROR);
}

int		read_byte(int fd, size_t size)
{
	unsigned char	buff[size];
	unsigned int	value;
	size_t			i;
	size_t			read_val;

	i = 0;
	read_val = read(fd, buff, size);
	value = buff[0];
	while (i < read_val)
	{
		value <<= 8;
		value |= buff[i];
		i++;
	}
	return (value);
}
