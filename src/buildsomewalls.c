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

uint32_t    paint_wall_slice(t_player *player, t_vars *game, int x, uint32_t *pixar)
{
    uint32_t    paint;
    int         y;
    int         i;

    y = player->y_texture;
    i = y * game->texture->width + x * (int)game->texture->bytes_per_pixel;
    if (i < 0 || i >= (int)(game->texture->width * game->texture->height))
        return 0;
    paint = pixar[i];
    return (paint);
}

int    x_texture(t_vars *game)
{
    if (game->player->ray->side == 1)
        game->hit_pos = game->player->x_pos + game->player->ray->perp_wall_dist * game->player->ray->x_ray_dir;
    else
        game->hit_pos = game->player->y_pos + game->player->ray->perp_wall_dist * game->player->ray->y_ray_dir;
    game->hit_pos -=  (floor)(game->hit_pos);
    game->player->x_texture = (int)(game->hit_pos/2 * (double)game->texture->width) /*%TEXTURE_W*/;
    // if ((game->player->ray->x_ray_dir > 0 && game->player->ray->side == 0) || 
    //     (game->player->ray->y_ray_dir < 0 && game->player->ray->side == 1))
    //     game->player->x_texture = game->texture->width - game->player->x_texture - 1;
    if (game->player->x_texture < 0)
        game->player->x_texture = 0;
    if (game->player->x_texture >= (int)game->texture->width)
        game->player->x_texture = (int)game->texture->width - 1;
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
    x_of_texture = x_texture(game);
    // printf("x_texture: %d\n", player->x_texture);
    j = game->texture->height / player->ray->wall_slice_height;
    pos_of_texture = (i - (SCREEN_HEIGHT / 2 - player->ray->wall_slice_height / 2)) * j;
    while (i < player->wall_slice_end)
    {
        player->y_texture = (int)pos_of_texture;
        if (game->player->y_texture < 0)
            game->player->y_texture = 0;
        if (game->player->y_texture >= (int)game->texture->height)
            game->player->y_texture = (int)game->texture->height - 1;
        pos_of_texture += j;
        game->wall_paint = paint_wall_slice(player, game, x_of_texture, (uint32_t *)game->texture->pixels);
        game->wall_paint = (game->wall_paint << 24) | (((game->wall_paint >> 16) << 24) >> 16) | \
			(((game->wall_paint << 16) >> 24) << 16) | (game->wall_paint >> 24);
        mlx_put_pixel(game->image, x, i, game->wall_paint);
        i++;
    }
}
void    wall_slicing(t_vars *game)
{
    int     x;

    x = 0;
    game->player->ray = malloc(sizeof(t_ray));
    if (game->player->ray == NULL)
        error_msg_and_exit(MALLOC_FAIL, "game->player->ray", game);
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
        x++;
    }
}
 