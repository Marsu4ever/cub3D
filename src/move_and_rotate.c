/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:34:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/28 14:03:05 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    rotate_left(t_vars *game)
{
    double  old_xdir;
    double  old_x_plane;

    old_xdir = game->player->xdir;
    game->player->xdir = game->player->xdir * cos(-ROT_SPEED) - game->player->ydir * sin(-ROT_SPEED);
    game->player->ydir = game->player->ydir * cos(-ROT_SPEED) + old_xdir * sin(-ROT_SPEED);
    old_x_plane = game->player->x_plane;
    game->player->x_plane = game->player->x_plane * cos(-ROT_SPEED) - game->player->y_plane * sin(-ROT_SPEED);
    game->player->y_plane = game->player->y_plane * cos(-ROT_SPEED) + old_x_plane * sin(-ROT_SPEED);
    wall_slicing(game);
}

void    rotate_right(t_vars *game)
{
    double  old_xdir;
    double  old_x_plane;

    old_xdir = game->player->xdir;
    game->player->xdir = game->player->xdir * cos(ROT_SPEED) - game->player->ydir * sin(ROT_SPEED);
    game->player->ydir = game->player->ydir * cos(ROT_SPEED) + old_xdir * sin(ROT_SPEED);
    old_x_plane = game->player->x_plane;
    game->player->x_plane = game->player->x_plane * cos(ROT_SPEED) - game->player->y_plane * sin(ROT_SPEED);
    game->player->y_plane = game->player->y_plane * cos(ROT_SPEED) + old_x_plane * sin(ROT_SPEED);
    wall_slicing(game);
}

void    move_w(t_vars *game)
{
    wall_slicing(game);
}

void    move_a(t_vars *game)
{
    wall_slicing(game);
}

void    move_s(t_vars *game)
{
    wall_slicing(game);
}

void    move_d(t_vars *game)
{
    wall_slicing(game);
}
