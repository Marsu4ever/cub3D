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

uint32_t    paint_wall_slice(t_player *player, t_vars *game, int x)
{
    uint32_t    paint;
    int         y;
    int         i;

    y = player->y_texture;
    i = y * TEXTURE_W + x * game->texture->bytes_per_pixel;
    paint = (uint32_t)get_rgba(game->texture->pixels[i], game->texture->pixels[i + 1], game->texture->pixels[i + 2]);
    return (paint);
}

int    texture_coordinates(t_vars *game)
{
    if (game->player->ray->side == 1) //y-axis
        game->x_hit = game->player->x_pos + game->player->ray->perp_wall_dist * game->player->ray->x_ray_dir;
    else //x-axis
        game->x_hit = game->player->y_pos + game->player->ray->perp_wall_dist * game->player->ray->y_ray_dir;
    game->x_hit -=  (int)(game->x_hit);
    game->player->x_texture = (int)(game->x_hit * TEXTURE_W /*+ 25*/) /*% TEXTURE_W*/;
    // if ((game->player->ray->x_ray_dir > 0 && game->player->ray->side == 0) || 
    //     (game->player->ray->y_ray_dir < 0 && game->player->ray->side == 1))
    //     game->player->x_texture = TEXTURE_W - game->player->x_texture - 1;
    // if (game->player->x_texture < 0)
    //     game->player->x_texture = 0;
    // if (game->player->x_texture >= TEXTURE_W)
    //     game->player->x_texture = TEXTURE_W - 1;
    return (game->player->x_texture);
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
    int             x_of_texture;
    double          j;
    double          pos_of_texture;

    i = player->wall_slice_start;
    game->texture = texture_pick(game);
    x_of_texture = texture_coordinates(game);
    j = (double)TEXTURE_H / player->ray->wall_slice_height;
    pos_of_texture = (i - (SCREEN_HEIGHT / 2 - player->ray->wall_slice_height / 2)) * j;
    while (i < player->wall_slice_end)
    {
        player->y_texture = (int)pos_of_texture % TEXTURE_H;
        // if (player->y_texture < 0)
        //     player->y_texture = 0;
        //  if (player->y_texture >= TEXTURE_H)
        //     player->y_texture = TEXTURE_H - 1;
        game->wall_paint = paint_wall_slice(player, game, x_of_texture);
        mlx_put_pixel(game->image, x, i, game->wall_paint);
        pos_of_texture += j;
        i++;
    }
    printf("x_texture: %d\n", player->x_texture);
    // exit(0);
}

void    wall_slicing(t_vars *game)
{
    int     x;

    x = 0;
    game->player->ray = malloc(sizeof(t_ray)); //Add NULL protection
    while (x < SCREEN_WIDTH)
    {
        init_rays(game->player, x);
        calc_rays(game);
        game->player->wall_slice_start = SCREEN_HEIGHT/2 - game->player->ray->wall_slice_height/2;
        if (game->player->wall_slice_start < 0)
            game->player->wall_slice_start = 0;
        game->player->wall_slice_end = game->player->ray->wall_slice_height/2 + SCREEN_HEIGHT/ 2;
        if (game->player->wall_slice_end >= SCREEN_HEIGHT)
            game->player->wall_slice_end = SCREEN_HEIGHT - 1;
        create_the_maze(x, game);
        // printf("wall_slice_start: %f, wall_slice_end: %f\n", game->player->wall_slice_start, game->player->wall_slice_end);
        // printf("wall_slice_height: %f\n", game->player->ray->wall_slice_height);
        x++;
    }
}
 