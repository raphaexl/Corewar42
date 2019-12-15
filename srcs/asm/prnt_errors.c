/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:40:18 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/10 18:28:17 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

char	*errno_msg_i(int my_errno)
{
	if (my_errno == e_errors_RedifineALab)
		return ("Redifining a lable");
	else if (my_errno == e_errors_InvFileName)
		return ("Using Unsupported file format");
	else if (my_errno == e_errors_UndefinedLab)
		return ("Undefined Label");
	else if (my_errno == e_errors_UndefinedInst)
		return ("Undefined Instruction");
	else if (my_errno == e_errors_UndefinedBehaviour)
		return ("Undefined Behavior");
	else if (my_errno == e_errors_NameLenExceeded)
		return ("Program name length exceeded");
	else if (my_errno == e_errors_CommentLenExceeded)
		return ("Program comment length exceeded");
	else if (my_errno == e_errors_ForkError)
		return ("Fork failed to create a child process");
	return ("Undefined Behavior");
}

char	*errno_msg(int my_errno)
{
	if (my_errno == e_errors_Usage)
		return ("Usage: ./asm <sourcefile.s>");
	if (my_errno == e_errors_CantOpenFileWrite)
		return ("Can't open file for writing");
	if (my_errno == e_errors_CantOpenFileRead)
		return ("Can't open file for reading");
	else if (my_errno == e_errors_SyntaxError)
		return ("Syntax Error");
	else if (my_errno == e_errors_MallocError)
		return ("Malloc memory allocation problem");
	else if (my_errno == e_errors_InvlidParam)
		return ("Invalid parameter");
	else if (my_errno == e_errors_InvlidParamCount)
		return ("Invalid parameter count");
	else if (my_errno == e_errors_NonExistentLable)
		return ("Use of an undefined lable");
	else if (my_errno == e_errors_NoStatTerminator)
		return ("Statement terminator missing");
	else if (my_errno == e_errors_ForbiddenCharLab)
		return ("Use of forbidden characters in a Label");
	else
		return (errno_msg_i(my_errno));
}

void	prnt_errors(char *costum_msg, int my_errno, t_file *file)
{
	if (my_errno > e_errors_BreakPoint)
	{
		if (costum_msg)
			ft_printf("%s Line[%d]: %s\n",
				errno_msg(my_errno), file->parser.curline, costum_msg);
		else
			ft_printf("%s Line [%d]\n",
				errno_msg(my_errno), file->parser.curline);
	}
	else
	{
		if (costum_msg)
			ft_printf("%s: %s\n",
				errno_msg(my_errno), costum_msg);
		else
			ft_printf("%s\n", errno_msg(my_errno));
	}
	if (!file)
		exit(0);
	cleanup(file, 1);
}
