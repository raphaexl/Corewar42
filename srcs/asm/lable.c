/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lable.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:16:40 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 16:52:52 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	fill_lable(t_lable *lable, char *package, int new, t_file *file)
{
	char *tmp;
	char *tmp0;

	if (new && lable->lable_pos != -1)
	{
		if (!(lable->next = (t_lable *)malloc(sizeof(t_lable))))
			prnt_errors(NULL, e_errors_MallocError, NULL);
		lable = lable->next;
		lable->name = ft_strdup(".");
	}
	else
	{
		tmp = lable->name;
		lable->name = ft_strjoin(lable->name, ".");
		free(tmp);
	}
	tmp = lable->name;
	tmp0 = ft_strdup(package);
	lable->name = ft_strjoin(lable->name, tmp0);
	free(tmp);
	free(tmp0);
	lable->lable_pos = file->parser.insts->index;
	lable->next = NULL;
}

t_bool	lab_in_str(const char *str, const char *lab)
{
	int i;
	int j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && ++i)
		{
			j = 0;
			while (str[i + j] == lab[j] && str[i + j] != '\0')
			{
				j++;
				if (lab[j] == '\0' && (str[i + j] == '.' || str[i + j] == '\0'))
				{
					return (true);
				}
			}
		}
		if (str[i] != '\0')
			i++;
	}
	return (false);
}

void	store_lable(t_lable *lable, char *package, int new, t_file *file)
{
	int		i;

	i = 0;
	while (package[i] != '\0')
	{
		if (!ft_strchr(LABEL_CHARS, package[i]))
			prnt_errors(package, e_errors_ForbiddenCharLab, file);
		i++;
	}
	while (lable && lable->lable_pos != -1)
	{
		if (new && lab_in_str(lable->name, package))
			prnt_errors(package, e_errors_RedifineALab, file);
		else if (lab_in_str(lable->name, package))
			return ;
		if (!lable->next)
			break ;
		lable = lable->next;
	}
	fill_lable(lable, package, new, file);
}

int		lab_to_intg(t_lable *lable, char *package, t_file *file)
{
	(void)file;
	while (package[0] == DIRECT_CHAR || package[0] == LABEL_CHAR)
		package++;
	while (lable)
	{
		if (lab_in_str(lable->name, package))
		{
			return (lable->lable_pos);
		}
		lable = lable->next;
	}
	return (-1);
}

void	get_labs_vals(int lab_p, t_lable *lable, t_inst *instptr, t_file *file)
{
	int j;
	int i;

	j = 0;
	while (j < lab_p)
	{
		i = 0;
		while (i <= instptr->num_tokens - 1)
		{
			if (instptr->tokens[i].condlab == true)
			{
				if ((instptr->tokens[i].intg_content =\
					lab_to_intg(lable, instptr->tokens[i].content, file)) == -1)
					prnt_errors(NULL, e_errors_UndefinedLab, file);
			}
			i++;
		}
		instptr = instptr->next;
		j++;
	}
}
