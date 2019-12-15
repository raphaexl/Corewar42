/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 21:02:18 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/12/12 17:07:10 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assembler.h"

void	assamble(t_file *file, int fd)
{
	int			i;

	i = 0;
	if (!(file->arrinsts = (t_inst*)malloc(sizeof(t_inst) * file->nb_insts)))
		prnt_errors(NULL, e_errors_MallocError, file);
	while (i < file->nb_insts)
	{
		file->arrinsts[i] = *file->parser.insts;
		file->arrinsts[i].index = i;
		file->parser.insts = file->parser.insts->next;
		i++;
	}
	header_write(fd, file);
	write_bytecode(file->arrinsts, fd, file->nb_insts);
}

void	check_extension(int argc, char **argv, t_file *file)
{
	int i;

	i = ft_strlen(argv[argc - 1]) - 1;
	if (!(file->filename = ft_memalloc(i + 1)))
		prnt_errors(NULL, e_errors_MallocError, NULL);
	if ((i < 0 || argv[argc - 1][i--] != 's'))
	{
		free(file->filename);
		prnt_errors(NULL, e_errors_InvFileName, NULL);
	}
	if ((i < 0 || argv[argc - 1][i--] != '.'))
	{
		free(file->filename);
		prnt_errors(NULL, e_errors_InvFileName, NULL);
	}
	while (i >= 0)
	{
		file->filename[i] = argv[argc - 1][i];
		i--;
	}
}

void	handle_this_file(int argc, char **argv)
{
	int		fd_r;
	int		fd_w;
	t_file	file;
	char	*tmp;

	check_extension(argc, argv, &file);
	if ((fd_r = open(argv[argc - 1], O_RDONLY)) == -1)
		prnt_errors(NULL, e_errors_CantOpenFileRead, NULL);
	parser(fd_r, &file);
	tmp = file.filename;
	if (!(file.filename = ft_strjoin(file.filename, EXTENTION)))
		prnt_errors(NULL, e_errors_MallocError, NULL);
	free(tmp);
	if ((fd_w = open(file.filename, O_CREAT | O_TRUNC | O_RDWR,\
					S_IWUSR | S_IRUSR)) == -1)
		prnt_errors(NULL, e_errors_CantOpenFileWrite, &file);
	assamble(&file, fd_w);
	ft_printf("Writing output to: %s\n", file.filename);
	cleanup(&file, 0);
	free(file.arrinsts);
	close(fd_r);
	close(fd_w);
	exit(0);
}

int		main(int argc, char **argv)
{
	int fork_ret;

	if (argc == 1)
		prnt_errors(NULL, e_errors_Usage, NULL);
	while (argc > 1)
	{
		if ((fork_ret = fork()) == 0)
		{
			handle_this_file(argc, argv);
		}
		else if (fork_ret == -1)
			prnt_errors(NULL, e_errors_ForkError, NULL);
		wait(NULL);
		argc--;
	}
	return (0);
}
