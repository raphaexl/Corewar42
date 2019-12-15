/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:41:11 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 16:53:28 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	clean_labs(t_file *file)
{
	t_lable *lab;

	while (file->parser.lable)
	{
		free(file->parser.lable->name);
		lab = file->parser.lable;
		file->parser.lable = file->parser.lable->next;
		free(lab);
	}
}

void	cleanup(t_file *file, t_bool error)
{
	int		i;
	t_inst	*inst;

	i = 0;
	free(file->filename);
	if (file->name)
		free(file->name);
	if (file->comment)
		free(file->comment);
	while (file->parser.instshead)
	{
		i = 0;
		while (i < file->parser.instshead->num_tokens)
		{
			free(file->parser.instshead->tokens[i].content);
			i++;
		}
		inst = file->parser.instshead;
		file->parser.instshead = file->parser.instshead->next;
		free(inst);
	}
	clean_labs(file);
	if (error)
		exit(0);
}

t_str	getter(int fd, char *endfline, t_file *file)
{
	char	buff[2];
	t_str	str;
	int		ret;
	char	*strtmp;

	str.len = 0;
	str.content = NULL;
	if (!(str.content = (char*)ft_memalloc(1)))
		prnt_errors(NULL, e_errors_MallocError, file);
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[1] = '\0';
		strtmp = ft_strjoin(str.content, buff);
		ft_memdel((void**)&str.content);
		if (!strtmp)
			prnt_errors(NULL, e_errors_MallocError, file);
		str.content = strtmp;
		if (++str.len && buff[0] == '\n')
			file->parser.curline++;
		if (ft_strchr(endfline, buff[0]))
			return (str);
	}
	if (str.content[0] == '\0')
		my_memdel((void**)&str.content);
	return (str);
}

int		get_index(char *name)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(g_op_tab[i].name, name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		to_intg(char *package)
{
	while (!ft_isdigit(package[0]) && package[0] != '-')
		package++;
	return (ft_atoi(package));
}
