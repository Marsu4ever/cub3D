/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:09:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/30 13:33:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void dda_loop(t_player *player, t_vars *game)
{
    while (player->hit == 0)
    {
        // printf("x_side_dist: %f,  y_side_dist: %f\n", game->player->ray->x_side_dist, game->player->ray->y_side_dist);
        if (player->ray->x_side_dist < player->ray->y_side_dist) 
        {
            player->ray->x_side_dist += delta_dist(player->ray->x_ray_dir);
            game->x_map += player->x_step;
            player->ray->side = 0;
        }
        else
        {
            player->ray->y_side_dist += delta_dist(player->ray->y_ray_dir);
            game->y_map += player->y_step;
            player->ray->side = 1;
        }
        if (game->map[game->y_map][game->x_map] == '1' && pos_valid(game) == 1)
            player->hit = 1;
    }
}

void get_ray(t_player *player)
{
    player->ray->side = -1;
    if (player->ray->x_ray_dir >= 0)
    {
        player->x_step = 1;
        player->ray->x_side_dist = ((int)player->x_pos + 1.0 - player->x_pos) * delta_dist(player->ray->x_ray_dir);
    }
    else
    {
        player->x_step = -1;
        player->ray->x_side_dist = (player->x_pos - (int)player->x_pos) * delta_dist(player->ray->x_ray_dir);
    }
    if (player->ray->y_ray_dir >= 0)
    {
        player->y_step = 1;
        player->ray->x_side_dist = ((int)player->y_pos + 1.0 - player->y_pos) * delta_dist(player->ray->y_ray_dir);
    }
    else
    {
        player->y_step = -1;
        player->ray->x_side_dist = (player->y_pos - (int)player->y_pos) * delta_dist(player->ray->y_ray_dir);
    }
}

double delta_dist(double ray_dir)
{
    if (ray_dir != 0)
        return (fabs(1/ray_dir));
    else
        return (1e10);
}

void    init_rays(t_player  *player, int r)
{
    // printf("y_plane: %f, ydir: %f\n", player->y_plane, player->ydir);
    player->x_camera = 2 * r / (double)SCREEN_WIDTH - 1;
    player->ray->x_ray_dir = player->xdir + player->x_plane * player->x_camera;
    player->ray->y_ray_dir = player->ydir + player->y_plane * player->x_camera;
}

void    calc_rays(t_vars *game)
{
    game->player->hit = 0;
    get_ray(game->player);
    game->x_map = (int)game->player->x_pos;
	game->y_map = (int)game->player->y_pos;  
    dda_loop(game->player, game);
    if (game->player->ray->side == 1)
        game->player->ray->perp_wall_dist = game->player->ray->y_side_dist - delta_dist(game->player->ray->y_ray_dir);
    else
        game->player->ray->perp_wall_dist = game->player->ray->x_side_dist - delta_dist(game->player->ray->x_ray_dir);
    if (game->player->ray->perp_wall_dist == 0)
        game->player->ray->wall_slice_height = SCREEN_HEIGHT;
    else
        game->player->ray->wall_slice_height = ((int)SCREEN_HEIGHT / game->player->ray->perp_wall_dist); //perp_wall_dist is zero..
}
