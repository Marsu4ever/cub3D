/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/19 10:27:23 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	close_program(t_vars *game)
{
	mlx_terminate(game->mlx);
	game->mlx = NULL;
	destroy_textures(game);
	free_all(game);
	game = NULL;
}

int	main(int ac, char **av)
{
	t_vars	game;

	game = (t_vars){0};
	parsing(&game, ac, av);
	run_wolfenstein(&game);
	close_program(&game);
	return (0);
}
