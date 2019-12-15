/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchahid <kchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 01:15:37 by kchahid           #+#    #+#             */
/*   Updated: 2019/12/13 17:29:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../ft_printf/ft_printf.h"
# include "vm_op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <inttypes.h>
# include <limits.h>
# include <ncurses.h>

# define ARGS_ERROR		-4
# define FD_ERROR		-5
# define HM_ERROR		-6
# define NLB_ERROR		-7
# define PSIZE_ERROR 	-8

# define DUMP_32		32
# define DUMP_64		64

# define CYCLE_LOG      1
# define DEATH_LOG		2

typedef struct				s_exec
{
	unsigned char		*code;
	t_header			head;
}							t_exec;

typedef struct				s_arg
{
	int					dir_size;
	int					value;
	int					error;
}							t_arg;

typedef struct				s_op
{
	char				*name;
	int					nbr_arg;
	int					args[3];
	int					id_opcode;
	int					cycle_to_wait;
	char				description[50];
	int					index_args;
	int					size_dir;
	int					why;
}							t_op;

typedef struct				s_process
{
	int					id;
	int					player_id;
	int					carry;
	unsigned char		op_code;
	int					last_live;
	int					cycle_to_exec;
	short				count_st_sti;
	int					pc;
	int					pc_step;
	char				args[3];
	unsigned int		reg[REG_NUMBER];
	struct s_process	*next;
}							t_process;

typedef struct				s_player
{
	int					id;
	int					number;
	char				*name;
	int					first_pc;
	int					last_live;
	int					live;
	t_exec				*exec;
	struct s_player		*next;
}							t_player;

typedef struct				s_byte
{
	int					player;
	int					cp;
	int					status;
	char				content[3];
}							t_byte;

typedef struct				s_visu
{
	t_byte				bytes[64][64];
	int					wnr;
	int					quit;
	int					end_game;
	int					visu_spd;
	char				visu_event;
}							t_visu;

typedef struct				s_cmd
{
	int					tab[4];
	int					ac;
	char				**av;
}							t_cmd_arg;

typedef struct				s_vm
{
	int					nb_dump;
	int					dump;
	int					nb_player;
	int					cycle;
	int					old_cycle;
	int					cycle_to_die;
	int					check;
	int					lives;
	int					log;
	int					nbr_process;
	unsigned char		memory[MEM_SIZE];
	t_process			*process;
	t_player			*player;
	t_player			*winner;
	t_visu				*visu;
	t_cmd_arg			*cmd_arg;
}							t_vm;

void						parse(t_vm *vm);
void						parse_dump(t_vm *vm, char **av, int index);
int							cmp_dump(char *av);
int							check_is_digit_string(char *av);

int							cmp_visu(char *av);
void						parse_visu(t_vm *vm, char **av, int index);

int							cmp_log(char *av);
void						parse_log(t_vm *vm, char **av, int index);

void						parse_number(t_vm *vm, char **av, int index);
t_player					*create_new_player(t_vm *vm);
int							cmp_number(char *av);

int							corewar_header(char *s);
int							corewar_number(char **av, int index);
void						parse_other_think(t_vm *vm, char **av, int index);

void						parse_player(t_vm *vm);
int							search_id_player(t_vm *vm);
int							cmp_player_cor(char *av);

void						check_player(t_vm *vm);
void						swap_player(t_vm *vm, t_player *player);
void						case_2(t_player *tmp1, t_player *tmp2);
void						case_3(t_player *tmp1, t_player *tmp2, \
		t_player *tmp3);
void						case_4(t_player *tmp1, t_player *tmp2,\
		t_player *tmp3, t_player *tmp4);

void						pos_pc_player(t_vm *vm);

void						add_process(t_vm *vm);
void						add_to_struct_process(t_vm *vm, t_process *process);

void						parse_read(t_vm *vm);
t_exec						*read_code(t_vm *vm, char *file_name);
void						read_code_2(t_vm *vm, t_exec *code, int fd);
int							read_byte(int fd, size_t size);

void						clash_of_champ(t_vm *vm);
void						exec_process(t_vm *vm, t_process *process);
void						exec_opcode(t_vm *vm, t_process *process);
void						part_1(t_vm *vm, t_process *process, int op);
void						part_2(t_vm *vm, t_process *process, int op);

void						op_live(t_vm *vm, t_process *process);
void						copy_fork_lfork(t_vm *vm, t_process *process,\
		int pc);
void						op_zjmp(t_vm *vm, t_process *process);
void						op_st(t_vm *vm, t_process *process);
void						op_aff(t_vm *vm, t_process *process);
void						op_add_sub(t_vm *vm, t_process *process, int index);
void						op_fork_lfork(t_vm *vm, t_process *proces, int ind);
void						op_and_or_xor(t_vm *vm, t_process *proces, int ind);
void						op_ld_lld(t_vm *vm, t_process *process, int index);
void						op_ldi_lldi(t_vm *vm, t_process *proces, int index);
void						op_sti(t_vm *vm, t_process *process);

void						kill_process(t_vm *vm);
void						kill(t_vm *vm, t_process *p2, t_process *p3);
void						reset_var(t_vm *vm);

void						vm_error(t_vm *vm, int err_value);
void						malloc_error(t_vm	*vm);

void						vm_init(t_vm *vm, int ac, char **av);
void						vm_arena(t_vm *vm);
void						vm_log_and_dump(t_vm *vm);
void						vm_arena_display_32(t_vm *vm);
void						vm_arena_display_64(t_vm *vm);
void						vm_quit(t_vm *vm);

void						print_contestants(t_vm *vm);
void						print_winner(t_vm *vm);
int							print_exec_code_error(int err_code);
int							print_corewar_usage(void);

void						type_argument(t_process *process,\
		unsigned char arg_type, int nbr_arg);
int							arg_is_valid(t_process *process, int nbr_arg);

int							skip_byte(int arg_type, int nbr_param, int size);
int							int_byte(t_vm *vm, int pc);
short						short_byte(t_vm *vm, int pc);

int							step_add(int index_arg, int dir_size);
int							ft_skip_bytes(unsigned char arg_type, int nb_param,\
		int dir_size);

void						value_with_modulo(t_vm *vm, t_process *process,\
		t_arg *arg, int type_arg);
void						value_without_modulo(t_vm *vm, t_process *process,\
		t_arg *arg, int type_arg);
int							value_tdir(t_vm *vm, t_process *process,\
		int dir_size);
int							int_modulo(int value);
short						short_modulo(short value);

char						*ft_itoa_base_u(unsigned long long int value,\
		int base, int upper);
void						process_clean(t_process **process);
void						player_clean(t_player **players);
void						vm_visu(t_vm *vm, t_byte bytes[][64]);
void						draw_border();
void						init_clr(void);
void						init_vs(t_vm *vm);
void						vm_visu_event(char key, t_vm *vm);
void						zero(int a, int x, int y);
void						colors2(int *tbl, int player);
void						colors(int *tbl, int player);
int							in_pross(t_process *pross);
void						live_breakdown(int **tbl, t_vm *vm);
void						draw_breakdown(int n, t_vm *vm, int where, int p);
void						fill_game2(t_vm *vm, int *tbl);
void						fill_game(t_vm *vm);
void						refresh_sleep(t_vm *vm);
void						draw_arena(t_byte arena[][64], t_vm *vm);
void						fill_arena(t_byte arena[][64],\
		unsigned char arena_un[4 * 1024], int a);
void						get_coor(int **tbl, int pc);
int							null_bytes(t_byte arena[][64], int *tbl);
int							null_byte(t_byte arena[][64], int a, int b);
void						put_playeer(t_byte arena[][64], t_process *pross, \
		int *tbl);
void						put_player(int *tbl, t_byte arena[][64], \
		t_process *pross);
void						fill_player(t_byte arena[][64], t_process *pross);
void						fill_one(int *tbl, t_byte bytes[][64], t_player *p,\
		int pl);
void						fill_player_frst(t_byte bytes[][64], t_process *p,\
		t_vm *vm);
void						print_speed(t_vm *vm);
void						fill_info2(int i, t_vm *vm);
void						fill_info(t_vm *vm);
void						vm_visuu(t_vm *vm, t_byte bytes[][64], int i);
void						vm_winner(t_vm *vm);
t_player					*player_pointer(t_vm *vm, int i);

static t_op					g_op_tab[17] = {
	{
		.name = "",
		.nbr_arg = 0,
		.args = {0},
		.id_opcode = 0,
		.cycle_to_wait = 0,
		.description = " ",
		.index_args = 0,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "live",
		.nbr_arg = 1,
		.args = {T_DIR},
		.id_opcode = 1,
		.cycle_to_wait = 10,
		.description = "alive",
		.index_args = 0,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "ld",
		.nbr_arg = 2,
		.args = {T_DIR | T_IND, T_REG},
		.id_opcode = 2,
		.cycle_to_wait = 5,
		.description = "load",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "st",
		.nbr_arg = 2,
		.args = {T_REG, T_IND | T_REG},
		.id_opcode = 3,
		.cycle_to_wait = 5,
		.description = "store",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "add",
		.nbr_arg = 3,
		.args = {T_REG, T_REG, T_REG},
		.id_opcode = 4,
		.cycle_to_wait = 10,
		.description = "addition",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "sub",
		.nbr_arg = 3,
		.args = {T_REG, T_REG, T_REG},
		.id_opcode = 5,
		.cycle_to_wait = 10,
		.description = "soustraction",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "and",
		.nbr_arg = 3,
		.args = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		.id_opcode = 6,
		.cycle_to_wait = 6,
		.description = "et (and  r1, r2, r3   r1&r2 -> r3",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "or",
		.nbr_arg = 3,
		.args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.id_opcode = 7,
		.cycle_to_wait = 6,
		.description = "ou  (or   r1, r2, r3   r1 | r2 -> r3",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "xor",
		.nbr_arg = 3,
		.args = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		.id_opcode = 8,
		.cycle_to_wait = 6,
		.description = "ou (xor  r1, r2, r3   r1^r2 -> r3",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "zjmp",
		.nbr_arg = 1,
		.args = {T_DIR},
		.id_opcode = 9,
		.cycle_to_wait = 20,
		.description = "jump if zero",
		.index_args = 0,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "ldi",
		.nbr_arg = 3,
		.args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.id_opcode = 10,
		.cycle_to_wait = 25,
		.description = "load index",
		.index_args = 1,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "sti",
		.nbr_arg = 3,
		.args = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		.id_opcode = 11,
		.cycle_to_wait = 25,
		.description = "store index",
		.index_args = 1,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "fork",
		.nbr_arg = 1,
		.args = {T_DIR},
		.id_opcode = 12,
		.cycle_to_wait = 800,
		.description = "fork",
		.index_args = 0,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "lld",
		.nbr_arg = 2,
		.args = {T_DIR | T_IND, T_REG},
		.id_opcode = 13,
		.cycle_to_wait = 10,
		.description = "long load",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	},
	{
		.name = "lldi",
		.nbr_arg = 3,
		.args = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		.id_opcode = 14,
		.cycle_to_wait = 50,
		.description = "long load index",
		.index_args = 1,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "lfork",
		.nbr_arg = 1,
		.args = {T_DIR},
		.id_opcode = 15,
		.cycle_to_wait = 1000,
		.description = "long fork",
		.index_args = 0,
		.size_dir = 1,
		.why = 0
	},
	{
		.name = "aff",
		.nbr_arg = 1,
		.args = {T_REG},
		.id_opcode = 16,
		.cycle_to_wait = 2,
		.description = "aff",
		.index_args = 1,
		.size_dir = 0,
		.why = 0
	}
};

#endif
