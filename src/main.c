/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/07 11:23:02 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// static void init_player(t_vars *vars)
// {
//     t_player    *player;
    
//     player = malloc(sizeof(t_player));
//     if (!player)
//         msg_and_exit("Allocation of player was failed.\n", 2);
//     vars->player = player;
// }

int main (int ac, char **av)
{
    t_vars  game;
    int     fd;
    
	game = (t_vars){0};
    if (ac != 2)
        msg_and_exit("Please use only two arguments!!", 2);
    else
    {
        // init_player(&game);
        game.map_path = ft_strdup(av[1]);
        if (!game.map_path || (ft_strlen(game.map_path) > 5 &&
            ft_strncmp(&game.map_path[ft_strlen(game.map_path) - 4], ".cub", 4)))
            msg_and_exit("Wrong map input.\n", 2);
        fd = open(game.map_path, 2);
    	if (fd == -1)
            msg_and_exit("Fd not opened.\n", 2);
        parsing(fd, &game);
        calc_and_make_map(&game, av);
		mlx_functions(&game);
    }
}
