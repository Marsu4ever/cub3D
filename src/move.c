/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:34:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/13 15:26:12 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int hit_a_wall(t_vars *game, double new_x, double new_y)
{
    double  newer_x;
    double  newer_y;

    if (game->player->xdir > 0)
        newer_x = new_x + 0.2;
    else if (game->player->xdir < 0)
        newer_x = new_x - 0.2;
    else
        newer_x = new_x;
    if (game->player->ydir > 0)
        newer_y = new_y + 0.2;
    else if (game->player->ydir < 0)
        newer_y = new_y - 0.2;
    else
        newer_y = new_y;
    // if ((int)new_x < 0 || (int)new_x >= SCREEN_WIDTH || 
    // (int)new_y < 0 || (int)new_y >= SCREEN_HEIGHT ||
    // (int)newer_x < 0 || (int)newer_x >= SCREEN_WIDTH || 
    // (int)newer_y < 0 || (int)newer_y >= SCREEN_HEIGHT)
    //     return (1);
    if ((game->map[(int)new_y][(int)new_x] == '1') \
        || (game->map[(int)newer_y][(int)newer_x] == '1'))
        return (1);
    return (0);
}

void    move_w(t_vars *game)
{
    double  new_xpos;
    double  new_ypos;

    new_xpos = game->player->x_pos + game->player->xdir * MOVE_SPEED;
    new_ypos = game->player->y_pos + game->player->ydir * MOVE_SPEED;
    if (hit_a_wall(game, new_xpos, new_ypos) == 1)
        return ;
    game->player->x_pos = new_xpos;
    game->player->y_pos = new_ypos;
    // wall_slicing(game);
}

void    move_d(t_vars *game)
{
    double  new_xpos;
    double  new_ypos;

    new_xpos = game->player->x_pos + game->player->x_plane * MOVE_SPEED;
    new_ypos = game->player->y_pos + game->player->y_plane * MOVE_SPEED;
    if (hit_a_wall(game, new_xpos, new_ypos) == 1)
        return ;
    game->player->x_pos = new_xpos;
    game->player->y_pos = new_ypos;
    // wall_slicing(game);
}

void    move_s(t_vars *game)
{
    double  new_xpos;
    double  new_ypos;

    new_xpos = game->player->x_pos - game->player->xdir * MOVE_SPEED;
    new_ypos = game->player->y_pos - game->player->ydir * MOVE_SPEED;
    if (hit_a_wall(game, new_xpos, new_ypos) == 1)
        return ;
    game->player->x_pos = new_xpos;
    game->player->y_pos = new_ypos;
    // wall_slicing(game);
}

void    move_a(t_vars *game)
{
        double  new_xpos;
    double  new_ypos;

    new_xpos = game->player->x_pos - game->player->x_plane * MOVE_SPEED;
    new_ypos = game->player->y_pos - game->player->y_plane * MOVE_SPEED;
    if (hit_a_wall(game, new_xpos, new_ypos) == 1)
        return ;
    game->player->x_pos = new_xpos;
    game->player->y_pos = new_ypos;
    // wall_slicing(game);
}
