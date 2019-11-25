/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:08:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/25 19:53:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		main(int ac, char *av[])
{
	t_vm	vm;

	ft_bzero(&vm, sizeof(t_vm));
	ft_parse_args(&vm, ac, av);
	if (ft_read(&vm))
	{
		ft_putendl("error file reading :)");
		ft_vm_clean(&vm);
	}
	ft_arena_init(&vm);
	ft_arena_print(&vm);
	ft_arena_debug(&vm);
	ft_players_print(vm.players);
	ft_vm_clean(&vm);
	return (0);
}
