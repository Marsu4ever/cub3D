/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildsomewalls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:47:37 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/09 16:47:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    texture_coordinates(t_vars *game)
{
    if (game->player->side)
        game->texture_x = game->player->x_pos + game->player->perp_wall_dist * game->player->x_ray_dir;
    else
        game->texture_x = game->player->y_pos + game->player->perp_wall_dist * game->player->y_ray_dir;
    game->texture_x -=  (int)(game->texture_x);
    //will be finished tomorrow
}

void    put_textures(t_vars *game)
{
    if (game->player->side)
    {
        if (game->y_map <= game->player->y_pos)
            game->texture = game->south;
        else
            game->texture = game->north;
    }
    else
    {
        if (game->x_map <= game->player->x_pos)
            game->texture = game->west;
        else
            game->texture = game->east;
    }
    texture_coordinates(game);
}

void wall_slicing(t_vars *game)
{
    game->player->wall_height = (int)(SCREEN_HEIGHT / game->player->perp_wall_dist);
    game->player->start_of_wall = (SCREEN_HEIGHT - game->player->wall_height) / 2;
    if (game->player->start_of_wall < 0)
        game->player->start_of_wall = 0;
    game->player->end_of_wall = (game->player->wall_height + SCREEN_HEIGHT)/2;
    if (game->player->end_of_wall > SCREEN_HEIGHT)
        game->player->end_of_wall = SCREEN_HEIGHT - 1;
    put_textures(game);
}