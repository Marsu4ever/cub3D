/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 13:19:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int pos_valid(t_vars *game)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    j = 0;
    x = (int)game->pl->x_pos;
    y = (int)game->pl->y_pos;
    while (game->map[j])
        j++;
    if (j < y)
        return (0);
    while (game->map[y][i])
        i++;
    if (i < x)
        return (0);
    return (1);
}

void	close_program(t_vars *game)
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
