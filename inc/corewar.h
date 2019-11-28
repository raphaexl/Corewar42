/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:09:29 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:34:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define MAX_PLAYERS 4

# include "../libft/libft.h"
# include "op.h"
# include <sys/fcntl.h>

# define READ_SIZE 4

# include <stdio.h>

typedef struct	s_exec
{
	header_t		head;
	unsigned char	*code;
}				t_exec;

typedef struct	s_op
{
	char		*operation;
	int			nb_arg;
	char		arg[3];
	int			op_code;
	int			nb_cycles_wait;
	char		*op_description;
	int			carry;
	int			size_tdir;
}				t_op;

extern t_op op_tab[17];

typedef struct	s_player
{
	int					id;
	int					number;
	char				*name;
	t_exec				*exec;
	struct s_player		*next;
}				t_player;


typedef struct	s_carriage
{
	int					id;
	int					is_alive;
	int					carry;
	unsigned char		op_code;
	///unuseful for now  int					op_last_cycle;
	int 				verified;
	int					remaining_cylces;
	int					mem_cursor;
	int					cross_bytes;
	int					regs[REG_NUMBER];
	struct	s_carriage	*next;
}				t_carriage;


typedef struct	s_game
{
	int				cycles;
	int				nb_lives;
	int				cycles_to_die;
	int				nb_checks; // ?= 10
	int				nb_players; // ?= 10
	t_player		*last_alive_player;
	t_carriage		*carriage;
	t_player		*players;
	unsigned char	memory[MEM_SIZE];
}				t_game;

//life -value == number player

//this for parsing main arguments -n -d after -v (for visualisation)

typedef struct	s_vm_arg
{
	t_player	*players;
	int			nb_players;
	int			dump;
}				t_vm_arg;

typedef struct s_vm
{
	t_vm_arg	args;
	t_game		game;
}				t_vm;

t_player		*ft_player_new(int number, char *name);
void			ft_player_push_back(t_player **players, t_player *nw);
t_player		*ft_players_copy(t_player *players);
void			ft_players_print(t_player *players);
int				ft_players_length(t_player *players);
void			ft_player_free(t_player **players);

t_player		*ft_player_highest_number(t_player *players);

int				ft_champion_name(char *s);
int				ft_nonassigned(int tab[8]);
void			ft_parse_args(t_vm_arg *vm, int ac, char *av[]);

unsigned int	ft_unsigned_int(unsigned char *bytes);
unsigned int	ft_read_bytes(int fd, size_t size);
void			ft_write_bytes(unsigned char *buff, unsigned int code);
t_exec			*ft_read_code(const char *file_name);
int				ft_read(t_vm *vm);
void			ft_arena_init(t_game	*vm);
void			ft_arena_debug(t_game*vm);
void			ft_arena_print(t_game *vm);

unsigned char	ft_get_memory_byte(unsigned char memory[MEM_SIZE], int loc);
unsigned int	ft_read_mem_value(unsigned char memory[MEM_SIZE], int loc, size_t size);

void			ft_game_load(t_vm *vm);

void			ft_vm_load(t_vm *vm);
void			ft_vm_clean(t_vm *vm);

t_carriage		*ft_carriage_new(void);
void			ft_carriage_push_back(t_carriage **lst, t_carriage *nw);
void			ft_carriage_free(t_carriage **lst);

unsigned int	ft_atoi_base(const char *nbr, unsigned int base);

#endif
