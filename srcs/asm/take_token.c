/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:23:13 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:40:19 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

t_bool	breakf_spcl_sumbol(char **str, t_inst *inst)
{
	if ((str[0][0] != LABEL_CHAR || inst->optpos != -1) &&
			str[0][0] != SEPARATOR_CHAR &&
			((str[0][0] != ' ' && str[0][0] != '\t') || inst->optpos != -1) &&
			str[0][0] != '\n' && str[0][0] != '\0')
		return (true);
	return (false);
}

char	*tok_check_empty(char *str, char *package, t_file *file)
{
	if ((str[0] == '\n' || str[0] == '\0') && package[0] == '\0')
	{
		free(package);
		return (NULL);
	}
	else if (package[0] == '\0')
	{
		free(package);
		prnt_errors(NULL, e_errors_SyntaxError, file);
	}
	return (package);
}

char	*tok_comment(char *package)
{
	if (package[0] == '\0')
	{
		free(package);
		return (NULL);
	}
	return (package);
}

void	bad_character(t_bool space_in_tok, char **str,\
		char *package, t_file *file)
{
	if (space_in_tok &&
		!ft_strchr("#;", str[0][0]))
	{
		free(package);
		prnt_errors(NULL, e_errors_SyntaxError, file);
	}
}

char	*take_tok(char **str, t_inst *inst, t_file *file)
{
	int		j;
	char	*package;
	t_bool	space_in_tok;

	space_in_tok = false;
	j = 0;
	if (!(package = ft_memalloc(ft_strlen(str[0]) + 1)))
		prnt_errors(NULL, e_errors_MallocError, file);
	skip_spaces(str);
	while (breakf_spcl_sumbol(str, inst))
	{
		bad_character(space_in_tok, str, package, file);
		if ((str[0][0] == ' ' || str[0][0] == '\t') && (space_in_tok = true))
			skip_spaces(str);
		else
		{
			if (!ft_strchr(COMMENT_CHARS, str[0][0]))
				package[j] = str[0][0];
			else
				return (tok_comment(package));
			str[0]++;
			j++;
		}
	}
	return (tok_check_empty(*str, package, file));
}
