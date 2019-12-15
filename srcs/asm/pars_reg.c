/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_reg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:20:55 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:40:19 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_bool	param_check(t_inst *inst)
{
	if (g_op_tab[inst->optpos].args[inst->num_tokens - 1] & T_REG)
		return (true);
	return (false);
}

void	fill_reg(char *package, t_inst *inst, t_file *file)
{
	inst->inst_bytes++;
	file->prog_size++;
	inst->tokens[inst->num_tokens].nb_byte = 1;
	inst->tokens[inst->num_tokens].condlab = false;
	inst->tokens[inst->num_tokens].intg_content = to_intg(package);
	inst->tokens[inst->num_tokens].content = ft_strdup(package);
	inst->tokens[inst->num_tokens].type = T_REG;
}

int		check_reg_v(char *package, t_inst *inst, t_file *file)
{
	int i;

	i = 1;
	if (inst->optpos == -1)
		prnt_errors(NULL, e_errors_SyntaxError, file);
	else if (package[0] == 'r' && param_check(inst))
	{
		while (package[i] != '\0')
		{
			if (!ft_isdigit(package[i]) && !(package[i] == '-' && i == 1))
				prnt_errors(NULL, e_errors_SyntaxError, file);
			i++;
		}
		if ((package[i - 1] == '-' || package[i - 1] == 'r'))
			prnt_errors("INVALID REG PARAM FORMAT", e_errors_SyntaxError, file);
		fill_reg(package, inst, file);
		return (1);
	}
	else if (package[0] == 'r' && !param_check(inst))
		prnt_errors(NULL, e_errors_InvlidParam, file);
	return (0);
}
