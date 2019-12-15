/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:10:12 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 16:53:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

int		look_keyword(t_str stack, char *piece, t_file *file,\
		t_bool nocomment_noname)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((stack.content[i] == ' ' || stack.content[i] == '\t') && i++)
		;
	while (stack.len - 1 && piece[j] != '\0' &&
			stack.content[i] == piece[j] && ++j && ++i)
		stack.len--;
	if (piece[j] == '\0')
	{
		while (stack.len - 1 && (stack.content[i] == ' ' ||
				stack.content[i] == '\t') && j++)
			stack.len--;
		if (stack.content[j] != '"')
			prnt_errors(NULL, e_errors_SyntaxError, file);
		return (1);
	}
	else if (j == 0 && (stack.content[i] == COMMENT_CHAR ||
				stack.content[i] == ALT_COMMENT_CHAR))
		return (0);
	if (nocomment_noname)
		prnt_errors(NULL, e_errors_SyntaxError, file);
	return (0);
}

int		f_name_comment(char **dest, int fd, t_file *file)
{
	t_str	src;
	int		i;

	i = 0;
	src = getter(fd, "\"", file);
	if (src.content[src.len - 1] != '"')
	{
		free(src.content);
		prnt_errors("terminating '\"' missing", e_errors_SyntaxError, file);
	}
	src.content[src.len - 1] = '\0';
	*dest = src.content;
	src = getter(fd, "\n", file);
	while (src.content[i] == ' ' || src.content[i] == '\t')
		i++;
	if (src.content[i] != COMMENT_CHAR &&
		src.content[i] != ALT_COMMENT_CHAR && src.content[i] != '\n')
	{
		free(src.content);
		prnt_errors(NULL, e_errors_SyntaxError, file);
	}
	free(src.content);
	return (1);
}

void	skip_comments(t_str str, t_file *file)
{
	int i;

	i = 0;
	while ((str.content[i] == ' ' || str.content[i] == '\t'))
		i++;
	if (!ft_strchr(COMMENT_CHARS, str.content[i]) &&
			str.content[i] != '\n')
		prnt_errors(NULL, e_errors_SyntaxError, file);
}

int		name_comment(t_file *file, int fd)
{
	t_str	str;

	str = getter(fd, "\"\n", file);
	while (str.len)
	{
		if (str.content[str.len - 1] == '\n')
			skip_comments(str, file);
		else if (str.content[ft_strlen(str.content) - 1] == '"')
		{
			if (!file->name && look_keyword(str, ".name", file, false)
					&& my_memdel((void**)&str.content))
				return (f_name_comment(&file->name, fd, file));
			else if (!file->comment && look_keyword(str, ".comment", file, true)
					&& my_memdel((void**)&str.content))
				return (f_name_comment(&file->comment, fd, file));
		}
		free(str.content);
		str = getter(fd, "\"\n", file);
	}
	return (0);
}

void	get_name_comment(t_file *file, int fd)
{
	if (!name_comment(file, fd))
	{
		ft_printf("can't get name or comment\n");
		exit(0);
	}
	if (!name_comment(file, fd))
	{
		ft_printf("can't get name or comment\n");
		exit(0);
	}
	if (ft_strlen(file->name) > PROG_NAME_LENGTH)
		prnt_errors(NULL, e_errors_NameLenExceeded, file);
	if (ft_strlen(file->comment) > COMMENT_LENGTH)
		prnt_errors(NULL, e_errors_CommentLenExceeded, file);
}
