/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:19:52 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:00:20 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	fill_lab_dir(char *package, t_inst *inst, t_file *file)
{
	int i;
	int dirsize;

	dirsize = (g_op_tab[inst->optpos].shortdir) ? 2 : 4;
	i = 2;
	while (package[i] != '\0')
	{
		if (!ft_strchr(LABEL_CHARS, package[i]))
			prnt_errors(NULL, e_errors_ForbiddenCharLab, file);
		i++;
	}
	if (package[i - 1] == LABEL_CHAR)
		prnt_errors(NULL, e_errors_ForbiddenCharLab, file);
	inst->tokens[inst->num_tokens].condlab = true;
	inst->inst_bytes += dirsize;
	inst->tokens[inst->num_tokens].nb_byte = dirsize;
	file->prog_size += dirsize;
	inst->tokens[inst->num_tokens].content = ft_strdup(package);
	inst->tokens[inst->num_tokens].type = T_DIR;
}

void	fill_num_dir(char *package, t_inst *inst, t_file *file)
{
	int i;
	int	dirsize;

	dirsize = (g_op_tab[inst->optpos].shortdir) ? 2 : 4;
	i = 1;
	while (package[i] != '\0')
	{
		if (!ft_isdigit(package[i]) && !(package[i] == '-' && i == 1))
			prnt_errors("INVALID DIR PARAM FORMAT", e_errors_SyntaxError, file);
		i++;
	}
	if ((package[i - 1] == '-' || package[i - 1] == DIRECT_CHAR))
		prnt_errors("INVALID DIR PARAM FORMAT", e_errors_SyntaxError, file);
	inst->tokens[inst->num_tokens].intg_content = to_intg(package);
	inst->tokens[inst->num_tokens].condlab = false;
	inst->inst_bytes += dirsize;
	inst->tokens[inst->num_tokens].nb_byte = dirsize;
	file->prog_size += dirsize;
	inst->tokens[inst->num_tokens].content = ft_strdup(package);
	inst->tokens[inst->num_tokens].type = T_DIR;
}

int		check_dir_v(char *package, t_inst *inst, t_file *file)
{
	int i;

	i = 1;
	if (inst->optpos == -1)
		prnt_errors(NULL, e_errors_SyntaxError, file);
	else if (package[0] == DIRECT_CHAR &&
			(g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_DIR))
	{
		if (package[i] == LABEL_CHAR && i++)
			fill_lab_dir(package, inst, file);
		else
			fill_num_dir(package, inst, file);
		return (1);
	}
	else if (package[0] == DIRECT_CHAR &&
			!(g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_DIR))
		prnt_errors(NULL, e_errors_InvlidParam, file);
	return (0);
}
