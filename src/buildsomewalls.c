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

uint32_t    paint_wall_slice(t_player *player, t_vars *game)
{
    uint32_t    paint;
    int         x_coordinate;
    int         y_coordinate;
    int         i;

    x_coordinate = player->x_texture;
    y_coordinate = player->y_texture;
    i = (y_coordinate * game->texture->height + x_coordinate) * 4;
    paint = (uint32_t)get_rgba(game->texture->pixels[i], game->texture->pixels[i + 1], game->texture->pixels[i + 2]);
    return (paint);
}

void    render_wall_slice(int r, t_player *player, t_vars *game)
{
    int     i;
    double  j;
    double  position_of_texture;

    i = player->wall_slice_start;
    j = TEXTURE_H / player->wall_slice_height;
    position_of_texture = player->wall_slice_start - SCREEN_HEIGHT/2.0 + player->wall_slice_height/2.0 * j;
    while (i < player->wall_slice_end)
    {
        player->y_texture = (int)position_of_texture & (TEXTURE_H - 1);
        position_of_texture += j;
        if (player->side)
            game->wall_paint = (game->wall_paint >> 1) & 8355711;
        else
            game->wall_paint = paint_wall_slice(player, game);
        mlx_put_pixel(game->image, r, i, game->wall_paint);
    }
}

void    texture_coordinates(t_vars *game)
{
    if (game->player->side == 1)
        game->x_wall = game->player->x_pos + game->player->perp_wall_dist * game->player->x_ray_dir;
    else
        game->x_wall = game->player->y_pos + game->player->perp_wall_dist * game->player->y_ray_dir;
    game->x_wall -=  (int)(game->x_wall);
    game->player->x_texture = (int)(game->x_wall) * TEXTURE_W;
    if ((game->player->x_ray_dir > 0 && game->player->side == 0) || 
        (game->player->y_ray_dir < 0 && game->player->side == 1))
        game->player->x_texture = TEXTURE_W - game->player->x_texture - 1;
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
    game->player->wall_slice_start = 0;
    game->player->wall_slice_end = 0;
    game->player->wall_slice_height = (int)(SCREEN_HEIGHT / game->player->perp_wall_dist);
    game->player->wall_slice_start = (SCREEN_HEIGHT - game->player->wall_slice_height) / 2;
    if (game->player->wall_slice_start < 0)
        game->player->wall_slice_start = 0;
    game->player->wall_slice_end = (game->player->wall_slice_height + SCREEN_HEIGHT)/2;
    if (game->player->wall_slice_end > SCREEN_HEIGHT)
        game->player->wall_slice_end = SCREEN_HEIGHT - 1;
    put_textures(game);
}
