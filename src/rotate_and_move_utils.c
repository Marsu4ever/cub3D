/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_move_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:53:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/13 14:44:54 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void    rotate_left(t_vars *game)
{
    double  old_xdir;
    double  old_x_plane;

    old_xdir = game->player->xdir;
    game->player->xdir = game->player->xdir * cos(ROT_SPEED) - game->player->ydir * sin(ROT_SPEED);
    game->player->ydir = game->player->ydir * cos(ROT_SPEED) + old_xdir * sin(ROT_SPEED);
    old_x_plane = game->player->x_plane;
    game->player->x_plane = game->player->x_plane * cos(ROT_SPEED) - game->player->y_plane * sin(ROT_SPEED);
    game->player->y_plane = game->player->y_plane * cos(ROT_SPEED) + old_x_plane * sin(ROT_SPEED);
    // wall_slicing(game);
}

void    rotate_right(t_vars *game)
{
    double  old_xdir;
    double  old_x_plane;

    old_xdir = game->player->xdir;
    game->player->xdir = game->player->xdir * cos(-ROT_SPEED) - game->player->ydir * sin(-ROT_SPEED);
    game->player->ydir = game->player->ydir * cos(-ROT_SPEED) + old_xdir * sin(-ROT_SPEED);
    old_x_plane = game->player->x_plane;
    game->player->x_plane = game->player->x_plane * cos(-ROT_SPEED) - game->player->y_plane * sin(-ROT_SPEED);
    game->player->y_plane = game->player->y_plane * cos(-ROT_SPEED) + old_x_plane * sin(-ROT_SPEED);
    // wall_slicing(game);
}
