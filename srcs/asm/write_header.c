/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:05:49 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 17:37:39 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	write_magic(int fd)
{
	int	nbr;
	int	swapped;

	nbr = COREWAR_EXEC_MAGIC;
	swappedbytes(&nbr, &swapped, 4);
	write(fd, &swapped, 4);
}

void	write_name(int fd, char *name)
{
	int		i;
	char	str[PROG_NAME_LENGTH];

	i = 0;
	ft_bzero(str, PROG_NAME_LENGTH);
	while (*name)
	{
		str[i] = *name;
		name++;
		i++;
	}
	write(fd, str, PROG_NAME_LENGTH);
}

void	write_progsize(int fd, int prog_size)
{
	int	nbr;

	swappedbytes(&prog_size, &nbr, 4);
	write(fd, &nbr, 4);
}

void	write_comment(int fd, char *comment)
{
	int		i;
	char	str[COMMENT_LENGTH];

	i = 0;
	ft_bzero(str, COMMENT_LENGTH);
	while (*comment)
	{
		str[i] = *comment;
		comment++;
		i++;
	}
	write(fd, str, COMMENT_LENGTH);
}

void	header_write(int fd, t_file *file)
{
	char	null[4];

	ft_bzero(&null, 4);
	write_magic(fd);
	write_name(fd, file->name);
	write(fd, &null, 4);
	write_progsize(fd, file->prog_size);
	write_comment(fd, file->comment);
	write(fd, &null, 4);
}
