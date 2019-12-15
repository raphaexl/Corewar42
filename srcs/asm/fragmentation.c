/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragmentation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:28:30 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:40:19 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_bool	reach_count(t_file *file)
{
	if (file->parser.insts->optpos != -1 &&
		file->parser.insts->num_tokens - 1 ==\
		g_op_tab[file->parser.insts->optpos].nb_param)
		return (true);
	return (false);
}

void	fragment_i(char **str, t_file *file, char *package)
{
	if (str[0][0] == LABEL_CHAR && str[0]++)
	{
		store_lable(file->parser.lable, package, file->parser.new_lab, file);
		file->parser.new_lab = false;
	}
	else if ((str[0][0] == ' ' || str[0][0] == '\t') &&
			file->parser.insts->optpos == -1 && str[0]++)
	{
		if (!store_inst(package, file->parser.insts, file))
			prnt_errors(package, e_errors_UndefinedInst, file);
	}
	else if (str[0][0] == SEPARATOR_CHAR && file->parser.insts->optpos != -1 &&
			file->parser.insts->num_tokens <\
			g_op_tab[file->parser.insts->optpos].nb_param && str[0]++)
		store_param(package, file->parser.insts, file);
	else if (file->parser.insts->optpos != -1)
		store_param(package, file->parser.insts, file);
	else
	{
		free(package);
		prnt_errors(NULL, e_errors_UndefinedInst, file);
	}
}

int		fragment(char *str, t_file *file)
{
	char *package;

	file->parser.insts->num_tokens = 0;
	file->parser.insts->optpos = -1;
	while (str[0] != '\n' && str[0] != '\0')
	{
		package = take_tok(&str, file->parser.insts, file);
		if (!package && reach_count(file))
			return (1);
		else if (!package)
			return (0);
		else if (file->parser.insts->optpos != -1 &&
				file->parser.insts->num_tokens - 1 >\
				g_op_tab[file->parser.insts->optpos].nb_param &&
				my_memdel((void**)&package))
			prnt_errors(NULL, e_errors_InvlidParamCount, file);
		else
			fragment_i(&str, file, package);
		free(package);
	}
	if (reach_count(file))
		return (1);
	else if (file->parser.insts->optpos != -1)
		prnt_errors(NULL, e_errors_InvlidParamCount, file);
	return (0);
}
