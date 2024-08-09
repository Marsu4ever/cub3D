/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/09 16:30:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void init_player(t_vars *vars)
{
    t_player    *player;
    
    player = malloc(sizeof(t_player));
    if (!player)
        msg_and_exit("Allocation of player was failed.\n", 2);
    vars->player = player;
}

int main (int ac, char **av)
{
    t_vars  game;
	
    game = (t_vars){0};
    game.player = NULL;
    
    init_player(&game);
    parsing(&game, ac, av);
    calc_and_make_map(&game, av);
    mlx_functions(&game);
    return (0);
}