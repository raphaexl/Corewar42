/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:08:46 by ebatchas          #+#    #+#             */
/*   Updated: 2019/11/28 22:30:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar.h"

int		main(int ac, char *av[])
{
	t_vm	vm;

	printf("value = %d\n", ft_atoi_base("c06a2", 16)); 
	ft_bzero(&vm, sizeof(t_vm));
	ft_parse_args(&vm.args, ac, av);
	if (ft_read(&vm))
	{
		ft_putendl("error file reading :)");
		ft_vm_clean(&vm);
	}
	ft_vm_load(&vm);
	ft_arena_init(&vm.game);
	ft_arena_print(&vm.game);
	ft_arena_debug(&vm.game);
	ft_players_print(vm.game.players);
	ft_vm_clean(&vm);
	return (0);
}
