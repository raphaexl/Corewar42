/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_inst_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:38:42 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:00:20 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	store_param(char *package, t_inst *inst, t_file *file)
{
	if (check_reg_v(package, inst, file) || check_dir_v(package, inst, file)
			|| check_indir_v(package, inst, file))
		inst->num_tokens++;
}

int		store_inst(char *package, t_inst *inst, t_file *file)
{
	if ((inst->optpos = get_index(package)) == -1)
		return (0);
	inst->inst_bytes = 1;
	file->prog_size++;
	if (g_op_tab[inst->optpos].typecode == 1)
	{
		file->prog_size++;
		inst->inst_bytes++;
	}
	inst->tokens[0].content = ft_strdup(package);
	inst->tokens[0].type = 0;
	inst->tokens[0].condlab = false;
	inst->tokens[0].intg_content = g_op_tab[inst->optpos].opcode;
	inst->num_tokens = 1;
	return (1);
}
