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
    i = y_coordinate * game->texture->width + x_coordinate;// * 4;
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
    game->player->x_texture = (int)(game->x_wall) * (double)TEXTURE_W;
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
    mlx_texture_t   *texture;

    i = player->wall_slice_start;
    texture = texture_pick(game);
    texture_coordinates(game);

    printf("\nWALL_SLICE_HEIGHT: %d\n", player->ray->wall_slice_height);
    
    j = game->texture->height / player->ray->wall_slice_height;
    position_of_texture = (i - SCREEN_HEIGHT/2 + player->ray->wall_slice_height/2) * j;
    while (i < player->wall_slice_end)
    {
        player->y_texture = (int)position_of_texture & (TEXTURE_H - 1);
        position_of_texture += (double)j;
        if (player->ray->side == 1)
            game->wall_paint = (game->wall_paint >> 1) & 8355711;
        else
            game->wall_paint = paint_wall_slice(player, game);
        mlx_put_pixel(game->image, x, i, game->wall_paint);
        i++;
    }
}

void    wall_slicing(t_vars *game)
{
    int     x;
    // t_ray   *ray;

    x = 0;
    game->player->ray = malloc(sizeof(t_ray));
    // ray = game->player->ray;
    while (x < SCREEN_WIDTH)
    {
        // game->player->wall_slice_start = 0;
        // game->player->wall_slice_end = 0;
        init_rays(game->player, x);
        calc_rays(game);
        printf("\nwall_slice_height: %d\n", game->player->ray->wall_slice_height);
        game->player->wall_slice_start = SCREEN_HEIGHT/2 - game->player->ray->wall_slice_height/2;
        if (game->player->wall_slice_start < 0)
            game->player->wall_slice_start = 0;
        game->player->wall_slice_end = game->player->ray->wall_slice_height/2 + SCREEN_HEIGHT/ 2;
        if (game->player->wall_slice_end >= SCREEN_HEIGHT)
            game->player->wall_slice_end = SCREEN_HEIGHT - 1;
        create_the_maze(x, game); //seg
        x++;
    }
}
