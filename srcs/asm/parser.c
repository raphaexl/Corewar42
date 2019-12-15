/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:36:15 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 16:51:44 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	init_file(t_file *file)
{
	file->comment = NULL;
	file->name = NULL;
	file->prog_size = 0;
	file->nb_insts = 0;
	if (!(file->parser.insts = (t_inst *)malloc(sizeof(t_inst) * 1)))
		prnt_errors(NULL, e_errors_MallocError, file);
	file->parser.instshead = file->parser.insts;
	file->parser.insts->next = NULL;
	file->parser.insts->num_tokens = 0;
	if (!(file->parser.lable = (t_lable *)malloc(sizeof(t_lable))))
		prnt_errors(NULL, e_errors_MallocError, file);
	file->parser.lable->next = NULL;
	file->parser.lable->lable_pos = -1;
	if (!(file->parser.lable->name = ft_memalloc(1)))
		prnt_errors(NULL, e_errors_MallocError, file);
	file->parser.new_lab = true;
	file->parser.curline = 0;
	file->parser.curline = 0;
}

void	init_inst(t_file *file)
{
	file->parser.new_lab = true;
	file->parser.insts = file->parser.insts->next;
	file->parser.insts->next = NULL;
	file->parser.insts->num_tokens = 0;
	file->nb_insts++;
	file->parser.insts->index = file->nb_insts;
}

void	parser(int fd, t_file *file)
{
	t_str	str;

	init_file(file);
	get_name_comment(file, fd);
	str = getter(fd, "\n", file);
	while (str.len)
	{
		if (fragment(str.content, file))
		{
			if (str.content[str.len - 1] != '\n')
				prnt_errors(NULL, e_errors_NoStatTerminator, file);
			if (!(file->parser.insts->next =\
				(t_inst *)malloc(sizeof(t_inst) * 1)))
				prnt_errors(NULL, e_errors_MallocError, file);
			init_inst(file);
		}
		free(str.content);
		str = getter(fd, "\n", file);
	}
	file->parser.insts = file->parser.instshead;
	get_labs_vals(file->nb_insts, file->parser.lable, file->parser.insts, file);
}
