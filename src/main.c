/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/01 12:49:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void init_vars(t_vars *vars)
{
    t_player    *player;
    
    player = malloc(sizeof(t_player));
    if (!player)
        msg_and_exit("Allocation of player was failed.\n", 2);
    vars->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Wolfenstein_3D", true);
    if (!vars->mlx)
        msg_and_exit("Mlx failed to be initialized.\n", 2);
    vars->player = player;
    vars->image = mlx_new_image(vars->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!vars->image)
    {
        mlx_close_window(vars->mlx);
        msg_and_exit("Image failed to be created.\n", 2);
    }
    if (mlx_image_to_window(vars->mlx, vars->image, 0, 0) == -1)
	{
		mlx_close_window(vars->mlx);
		msg_and_exit("Image failed to be converted to window.\n", 2);
	}
}

int main (int ac, char **av)
{
    t_vars  game;
    
	game = (t_vars){0};
    if (ac != 2)
        msg_and_exit("Please use only two arguments!!", 2);
    else
    {
        init_vars(&game);
        game.map_path = ft_strdup(av[1]);
        if (!game.map_path || (ft_strlen(game.map_path) > 5 &&
            ft_strncmp(&game.map_path[ft_strlen(game.map_path) - 4], ".cub", 4)))
            msg_and_exit("Wrong map input.\n", 2);
        calc_and_make_map(&game, av);
        //something
		mlx_functions(&game);
    }
}
