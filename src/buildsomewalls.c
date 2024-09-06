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
    i = y_coordinate * (int)TEXTURE_W + x_coordinate * game->texture->bytes_per_pixel;
    paint = (uint32_t)get_rgba(game->texture->pixels[i], game->texture->pixels[i + 1], game->texture->pixels[i + 2]);
    return (paint);
}

void    texture_coordinates(t_vars *game)
{
    if (game->player->ray->side == 1)
        game->x_wall = game->player->x_pos + game->player->ray->perp_wall_dist * game->player->ray->x_ray_dir;
    else
        game->x_wall = game->player->y_pos + game->player->ray->perp_wall_dist * game->player->ray->y_ray_dir;
    game->x_wall -=  floor(game->x_wall);
    game->player->x_texture = (int)(game->x_wall * (double)TEXTURE_W - 1); // -1)
    if ((game->player->ray->x_ray_dir > 0 && game->player->ray->side == 0) || 
        (game->player->ray->y_ray_dir < 0 && game->player->ray->side == 1))
        game->player->x_texture = TEXTURE_W - game->player->x_texture - 1;
}

mlx_texture_t    *texture_pick(t_vars *game)
{
    if (game->player->ray->side == 1)
    {
        if (game->player->ray->y_ray_dir < 0)
            game->texture = game->south;
        else if (game->player->ray->y_ray_dir > 0)
            game->texture = game->north;
    }
    else if (game->player->ray->side == 0)
    {
        if (game->player->ray->x_ray_dir > 0)
            game->texture = game->east;
        else if (game->player->ray->x_ray_dir < 0)
            game->texture = game->west;
    }
    return (game->texture);
}

void    render_wall_slice(int x, t_player *player, t_vars *game)
{
    int             i;
    double          j;
    double          position_of_texture;

    i = player->wall_slice_start;
    game->texture = texture_pick(game);
    texture_coordinates(game);
    j = (double)TEXTURE_H / (double)player->ray->wall_slice_height;
    position_of_texture = (i - SCREEN_HEIGHT / 2 + player->ray->wall_slice_height / 2) * j;
    while (i < player->wall_slice_end)
    {
        player->y_texture = (int)position_of_texture & (TEXTURE_H - 1);
        // if (player->y_texture >= TEXTURE_H)
        //     player->y_texture = TEXTURE_H - 1;
        // if (player->y_texture < 0)
        //     player->y_texture += TEXTURE_H;
        game->wall_paint = paint_wall_slice(player, game);
        mlx_put_pixel(game->image, x, i, game->wall_paint);
        position_of_texture += j;
        i++;
    }
}

void    wall_slicing(t_vars *game)
{
    int     x;

    x = 0;
    game->player->ray = malloc(sizeof(t_ray));//Add NULL protection
    while (x < SCREEN_WIDTH)
    {
        init_rays(game->player, x);
        calc_rays(game);
        game->player->wall_slice_start = (double)SCREEN_HEIGHT/2 - game->player->ray->wall_slice_height/2;
        // printf("wall_slice_START: %d\n", game->player->wall_slice_start);
        if (game->player->wall_slice_start < 0)
            game->player->wall_slice_start = 0;
        game->player->wall_slice_end = game->player->ray->wall_slice_height/2 + (double)SCREEN_HEIGHT/ 2;
        // printf("wall_slice_END: %d\n", game->player->wall_slice_end);
        if (game->player->wall_slice_end >= (double)SCREEN_HEIGHT)
            game->player->wall_slice_end = (double)SCREEN_HEIGHT - 1;
        // if ((game->player->wall_slice_start >= SCREEN_HEIGHT) || (game->player->wall_slice_end < 0))
        //     return ;
        if (game->player->wall_slice_end <= game->player->ray->wall_slice_height)
            printf("YES\n"); //stupid check
        else
            printf("YOU MADE IT!!!\n");
        create_the_maze(x, game);
        x++;
    }
}
 