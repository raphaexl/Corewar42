/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_indir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:19:14 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 14:58:00 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	fill_lab_indir(char *package, t_inst *inst, t_file *file)
{
	int i;

	i = 1;
	while (package[i] != '\0')
	{
		if (!ft_strchr(LABEL_CHARS, package[i]))
			prnt_errors(NULL, e_errors_ForbiddenCharLab, file);
		i++;
	}
	if (package[i - 1] == LABEL_CHAR)
		prnt_errors(NULL, e_errors_ForbiddenCharLab, file);
	file->prog_size += 2;
	inst->inst_bytes += 2;
	inst->tokens[inst->num_tokens].nb_byte = 2;
	inst->tokens[inst->num_tokens].condlab = true;
	inst->tokens[inst->num_tokens].content = ft_strdup(package);
	inst->tokens[inst->num_tokens].type = T_IND;
}

void	fill_num_indir(char *package, t_inst *inst, t_file *file)
{
	int i;

	i = 0;
	while (package[i] != '\0')
	{
		if (!ft_isdigit(package[i]) && !(package[i] == '-' && i == 0))
			prnt_errors("INVALID DIR PARAM FORMAT", e_errors_SyntaxError, file);
		i++;
	}
	if ((package[0] == '\0' || package[i - 1] == '-'))
		prnt_errors("INVALID DIR PARAM FORMAT", e_errors_SyntaxError, file);
	file->prog_size += 2;
	inst->inst_bytes += 2;
	inst->tokens[inst->num_tokens].nb_byte = 2;
	inst->tokens[inst->num_tokens].condlab = false;
	inst->tokens[inst->num_tokens].intg_content = to_intg(package);
	inst->tokens[inst->num_tokens].content = ft_strdup(package);
	inst->tokens[inst->num_tokens].type = T_IND;
}

int		check_indir_v(char *package, t_inst *inst, t_file *file)
{
	if (inst->optpos == -1)
		prnt_errors(NULL, e_errors_SyntaxError, file);
	if (package[0] == LABEL_CHAR &&
		(g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_IND))
	{
		fill_lab_indir(package, inst, file);
		return (1);
	}
	else if ((ft_isdigit(package[0]) || package[0] == '-') &&
			(g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_IND))
	{
		fill_num_indir(package, inst, file);
		return (1);
	}
	else if (!(g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_IND))
		prnt_errors(NULL, e_errors_InvlidParam, file);
	else
		prnt_errors(NULL, e_errors_SyntaxError, file);
	return (0);
}
