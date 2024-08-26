/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/23 11:42:03 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	init_player(t_vars *vars)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		msg_and_exit("Allocation of player was failed.\n", 2);
	/*
		-ft_memset?
	*/
	// player = (t_player*){0};
	vars->player = player;
}

void	close_program(t_vars *game)
{
	mlx_terminate(game->mlx);
	it_ends_here(game);
/*
		-After mlx_terminate

		-destroy textures??
		-free???		
*/
	
}

int	main(int ac, char **av)
{
	t_vars	game;

	game = (t_vars){0};
	game.player = NULL;

	init_player(&game);
	parsing(&game, ac, av);
	mlx_functions(&game);
	close_program(&game);
	return (0);
}