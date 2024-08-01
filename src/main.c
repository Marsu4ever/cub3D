/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/01 10:23:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int main (int ac, char **av)
{
    t_game  game;
    
	game = (t_game){0};
    if (ac != 2)
        msg_and_exit("Please use only two arguments!!");
    else
    {
        calc_and_make_map(&game, av);
        //something
		mlx_functions(&game);
    }
}
