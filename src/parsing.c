/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:30:43 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/05 13:30:43 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void orientation_calc(char *compass, t_vars *game)
{
    if (compass == 'N')
        n_s_compass(game->player, -1.0, FOV);
    else if (compass == 'E')
        e_w_compass(game->player, 1.0, FOV);
    else if (compass == 'S')
        n_s_compass(game->player, 1.0, -FOV);
    else
        e_w_compass(game->player, -1.0, -FOV);
}

int player_nbr_check(t_vars *game, char *row, int y)
{
    int i;

    i = 0;
    while (row[i])
    {
        if (row[i] == 'N' || row[i] == 'E' || row[i] == 'S' || row[i] == 'W')
        {
            orientation_calc(row[i], game);
            game->player->x_pos = (double)i + 0.3;
            game->player->y_pos = (double)y + 0.3;
            game->players_nbr++;
        }
        if (game->players_nbr > 0)
            return (1);
        i++;
    }
    return (0);
}

void check_map(t_vars *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        if (!player_amount_check(game, game->map[i], i))
            msg_and_exit("No players found..\n", 2);
        i++;
    }
}

void parsing(int fd, t_vars *game)
{
    check_map(&game);
}