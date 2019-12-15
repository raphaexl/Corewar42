/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_execode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:10:02 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 16:53:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	op_code(t_inst *inst, int rindex, int i, int fd)
{
	int	nbr;

	nbr = inst[rindex].tokens[i].intg_content;
	write(fd, &nbr, 1);
	if (g_op_tab[inst[rindex].optpos].typecode == 1)
		typecode(fd, inst[rindex].tokens, inst[rindex].num_tokens);
}

void	reg_code(t_inst *inst, int index, int i, int fd)
{
	int registervalue;

	registervalue = inst[index].tokens[i].intg_content;
	write(fd, &registervalue, inst[index].tokens[i].nb_byte);
}

void	dir_code(t_inst *inst, int index, int i, int fd)
{
	int	nbr;
	int	swapped;
	int	j;

	if (inst[index].tokens[i].content[1] == LABEL_CHAR)
	{
		j = inst[index].tokens[i].intg_content;
		nbr = nbbytes(index, inst, j);
		swappedbytes(&nbr, &swapped, inst[index].tokens[i].nb_byte);
		write(fd, &swapped, inst[index].tokens[i].nb_byte);
	}
	else
	{
		nbr = inst[index].tokens[i].intg_content;
		swappedbytes(&nbr, &swapped, inst[index].tokens[i].nb_byte);
		write(fd, &swapped, inst[index].tokens[i].nb_byte);
	}
}

void	ind_code(t_inst *inst, int index, int i, int fd)
{
	int	nbr;
	int	swapped;
	int	j;

	if (inst[index].tokens[i].content[0] == LABEL_CHAR)
	{
		j = inst[index].tokens[i].intg_content;
		nbr = nbbytes(index, inst, j);
		swappedbytes(&nbr, &swapped, inst[index].tokens[i].nb_byte);
		write(fd, &swapped, inst[index].tokens[i].nb_byte);
	}
	else
	{
		j = inst[index].tokens[i].intg_content;
		swappedbytes(&j, &swapped, inst[index].tokens[i].nb_byte);
		write(fd, &swapped, inst[index].tokens[i].nb_byte);
	}
}

void	write_bytecode(t_inst *inst, int fd, int nbinsts)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (index < nbinsts)
	{
		i = 0;
		while (i < inst[index].num_tokens)
		{
			if (inst[index].tokens[i].type == 0)
				op_code(inst, index, i, fd);
			else if (inst[index].tokens[i].type == T_REG)
				reg_code(inst, index, i, fd);
			else if (inst[index].tokens[i].type == T_DIR)
				dir_code(inst, index, i, fd);
			else if (inst[index].tokens[i].type == T_IND)
				ind_code(inst, index, i, fd);
			i++;
		}
		index++;
	}
}
