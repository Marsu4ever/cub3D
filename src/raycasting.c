/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:09:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/27 15:48:09 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void dda_loop(t_player *player, t_vars *game)
{
    while (player->hit == 0)
    {
        if (player->ray->x_side_dist < player->ray->y_side_dist) 
        {
            player->ray->x_side_dist += player->ray->x_delta_dist;
            game->x_map += player->x_step;
            player->ray->side = 0;
        }
        else
        {
            player->ray->y_side_dist += player->ray->y_delta_dist;
            game->y_map += player->y_step;
            player->ray->side = 1;
        }
        if (game->map[game->y_map][game->x_map] == '1' && pos_valid(game) == 1)
            player->hit = 1;
    }
}

t_ray *get_ray(t_player *player, t_vars * game)
{
    t_ray *ray;

    ray = player->ray;
    ray->side = -1;
    if (ray->x_ray_dir >= 0)
    {
        player->x_step = 1;
        ray->x_side_dist = ((double)game->x_map + 1.0 - player->x_pos) * ray->x_delta_dist;
    }
    else
    {
        player->x_step = -1;
        ray->x_side_dist = (player->x_pos - (double)game->x_map) * ray->x_delta_dist;
    }
    if (ray->y_ray_dir >= 0)
    {
        player->y_step = 1;
        ray->x_side_dist = ((double)game->y_map + 1.0 - player->y_pos) * ray->y_delta_dist;
    }
    else
    {
        player->y_step = -1;
        ray->x_side_dist = (player->y_pos - (double)game->y_map) * ray->y_delta_dist;
    }
    return (ray);
}

void delta_dist(t_player *player, t_vars *game)
{
    game->x_map = (int)player->x_pos;
	game->y_map = (int)player->y_pos;
    if (!player->ray->x_ray_dir)
		player->ray->x_delta_dist = 1e10; //(1/0) = 1e10
	else
		player->ray->x_delta_dist = fabs(1 / player->ray->x_ray_dir);
	if (!player->ray->y_ray_dir)
		player->ray->y_delta_dist = 1e10;
	else
		player->ray->y_delta_dist = fabs(1 / player->ray->y_ray_dir);
}

void    init_rays(t_player  *player, int r)
{
    player->x_camera = 2 * r / (double)SCREEN_WIDTH - 1;
    player->ray->x_ray_dir = player->xdir + player->x_plane * player->x_camera;
    player->ray->y_ray_dir = player->ydir + player->y_plane * player->x_camera;
}

void    calc_rays(t_vars *game)
{
    t_ray   *ray;

    delta_dist(game->player, game);
    game->player->hit = 0;
    ray = get_ray(game->player, game);
    game->x_map = (int)game->player->x_pos;
	game->y_map = (int)game->player->y_pos;
    dda_loop(game->player, game); 
    if (ray->side == 1)
        ray->perp_wall_dist = ray->x_side_dist - ray->x_delta_dist;
    else
        ray->perp_wall_dist = ray->y_side_dist - ray->y_delta_dist;
    if (ray->perp_wall_dist == 0)
        ray->wall_slice_height = SCREEN_HEIGHT;
    ray->wall_slice_height = ((int)SCREEN_HEIGHT / ray->perp_wall_dist);
}
