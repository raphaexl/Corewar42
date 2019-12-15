/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:12:07 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 17:43:15 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	typecode(int fd, t_token *tokens, int num_tokens)
{
	int rslt;
	int i;
	int j;
	int par[3];

	i = 1;
	j = 0;
	par[0] = 0;
	par[1] = 0;
	par[2] = 0;
	while (i < num_tokens)
	{
		if (tokens[i].type == T_DIR)
			par[j] = DIR_CODE;
		else if (tokens[i].type == T_IND)
			par[j] = IND_CODE;
		else if (tokens[i].type == T_REG)
			par[j] = REG_CODE;
		j++;
		i++;
	}
	rslt = (par[2] << 2 | par[1] << 4 | par[0] << 6);
	write(fd, &rslt, 1);
}
