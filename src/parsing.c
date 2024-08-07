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

void orientation_calc(char compass, t_vars *game)
{
    if (ft_strcmp(&compass, "N") == 0)
        n_s_compass(game->player, -1.0, FOV);
    else if (ft_strcmp(&compass, "E") == 0)
        e_w_compass(game->player, 1.0, FOV);
    else if (ft_strcmp(&compass, "S") == 0)
        n_s_compass(game->player, 1.0, -FOV);
    else if (ft_strcmp(&compass, "W") == 0)
        e_w_compass(game->player, -1.0, -FOV);
    printf("Orientation_calc\n");
}

void player_nbr_check(t_vars *game, char **map, int y)
{
    size_t j;

    j = 0;
    printf("Map[y] = %s", map[y]);
    while (j < ft_strlen(map[y]) - 1)
    {
        printf("map[i][j] = %c\n", map[y][j]);
        if (map[y][j] == 'N' || map[y][j] == 'W' || map[y][j] == 'E' || map[y][j] == 'S')
        {
            orientation_calc(map[y][j], game);
            game->player->x_pos = (double)j + 0.3;          
            game->player->y_pos = (double)y + 0.3;
            game->players_nbr++;
        }
        j++;
    }
}

void check_map(t_vars *game)
{
    int i;

    i = 0;
    while (game->map[i])
    {
        player_nbr_check(game, game->map, i);
        i++;
    }
    if (game->players_nbr == 0)
        msg_and_exit("No players found..\n", 2);
    printf("Number of players: %i", game->players_nbr);

}

void parsing(int fd, t_vars *game)
{
    (void)fd; //Markus will deal with this
    check_map(game);
}