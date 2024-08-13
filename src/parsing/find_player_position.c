/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:43 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/13 13:39:35 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void orientation_calc(char compass, t_vars *game)
{
    if (compass == 'N')
        n_s_compass(game->player, -1.0, FOV);
    else if (compass == 'E' == 0)
        e_w_compass(game->player, 1.0, FOV);
    else if (compass == 'S')
        n_s_compass(game->player, 1.0, -FOV);
    else if (compass == 'W')
        e_w_compass(game->player, -1.0, -FOV);
}

void set_player_position(t_vars *game, char **map, int y)
{
    size_t j;

    j = 0;
    while (j < ft_strlen(map[y]) - 1)
    {
        if (map[y][j] == 'N' || map[y][j] == 'W' || map[y][j] == 'E' || map[y][j] == 'S') /*This function implies that we have multiple 1st players. Is this a multiplayer game? :D */
        {
            orientation_calc(map[y][j], game);
            game->player->x_pos = (double)j;          
            game->player->y_pos = (double)y;
            game->players_nbr++;
        }
        j++;
    }
}

void find_player_position(t_vars *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        set_player_position(game, game->map, i);
        i++;
    }
}
