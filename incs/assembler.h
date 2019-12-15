/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:55:31 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 17:04:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSEMBLER_H
# define ASSEMBLER_H
# include "asm_op.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# define EXTENTION	".cor"

typedef enum			e_bool
{
	false,
	true,
}						t_bool;

enum					e_errors
{
	e_errors_Usage,
	e_errors_CantOpenFileWrite,
	e_errors_CantOpenFileRead,
	e_errors_InvFileName,
	e_errors_MallocError,
	e_errors_ForkError,
	e_errors_NonExistentLable,
	e_errors_UndefinedLab,
	e_errors_BreakPoint,
	e_errors_SyntaxError,
	e_errors_InvlidParam,
	e_errors_InvlidParamCount,
	e_errors_NoStatTerminator,
	e_errors_ForbiddenCharLab,
	e_errors_RedifineALab,
	e_errors_UndefinedInst,
	e_errors_UndefinedBehaviour,
	e_errors_NameLenExceeded,
	e_errors_CommentLenExceeded,
};

t_op	g_op_tab[17];

typedef struct			s_str
{
	char	*content;
	int		len;
}						t_str;

typedef	struct			s_token
{
	t_bool				condlab;
	int					type;
	int					nb_byte;
	char				*content;
	int					intg_content;
}						t_token;

typedef struct			s_lable
{
	int				lable_pos;
	char			*name;
	struct s_lable	*next;
}						t_lable;

typedef	struct			s_inst
{
	int					index;
	int					optpos;
	int					num_tokens;
	t_token				tokens[4];
	int					inst_bytes;
	struct s_inst		*next;
}						t_inst;

typedef struct			s_pars
{
	int				curline;
	t_bool			new_lab;
	t_lable			*lable;
	t_inst			*insts;
	t_inst			*instshead;
}						t_pars;

typedef	struct			s_file
{
	char				*filename;
	int					prog_size;
	char				*name;
	char				*comment;
	int					nb_insts;
	t_pars				parser;
	t_inst				*arrinsts;
}						t_file;

int						nbbytes(int index, t_inst *inst, int wanted);
void					typecode(int fd, t_token *tokens, int num_tokens);
void					write_bytecode(t_inst *inst, int fd, int nbinsts);
int						count_bytes(t_inst *one, int nbinst);
void					write_magic(int fd);
void					write_name(int fd, char *name);
void					header_write(int fd, t_file *file);
void					dissisamble(int fd);
void					swappedbytes(void *src, void *dst, int size);
int						get_index(char *name);
int						to_intg(char *package);
t_str					getter(int fd, char *endfline, t_file *file);
void					cleanup(t_file *file, t_bool error);
int						my_memdel(void **ap);
int						fragment(char *str, t_file *file);
void					get_labs_vals(int lab_p, t_lable *lable,\
										t_inst *instptr, t_file *file);
void					store_lable(t_lable *lable, char *package,\
										int new, t_file *file);
void					get_name_comment(t_file *file, int fd);
int						check_dir_v(char *package, t_inst *inst, t_file *file);
void					parser(int fd, t_file *file);
int						check_indir_v(char *package,\
										t_inst *inst, t_file *file);
int						check_reg_v(char *package, t_inst *inst, t_file *file);
void					prnt_errors(char *costum_msg,\
									int my_errno, t_file *file);
int						store_inst(char *package, t_inst *inst, t_file *file);
void					store_param(char *package, t_inst *inst, t_file *file);
char					*take_tok(char **str, t_inst *inst, t_file *file);
void					skip_spaces(char **str);

#endif
