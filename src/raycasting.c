/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:09:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/09 11:17:30 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// void dda_loop(t_player *player, t_vars *game)
// {
//     //update of x_side_dist and y_side_dist if a ray hits a wall
// }

void calc_rays(t_player *player, t_vars * game)
{
    if (player->x_ray_dir >= 0)
    {
        player->x_step = 1;
        player->x_side_dist = ((double)game->x_map + 1.0 - player->x_pos) * player->x_delta_dist;
    }
    else
    {
        player->x_step = -1;
        player->x_side_dist = (player->x_pos - (double)game->x_map) * player->x_delta_dist;
    }
    if (player->y_ray_dir >= 0)
    {
        player->y_step = 1;
        player->x_side_dist = ((double)game->y_map + 1.0 - player->y_pos) * player->y_delta_dist;
    }
    else
    {
        player->y_step = -1;
        player->x_side_dist = (player->y_pos - (double)game->y_map) * player->y_delta_dist;
    }
}

void delta_dist(t_player *player, t_vars *game)
{
    game->x_map = (int)player->x_pos;
	game->y_map = (int)player->y_pos;
	if (!player->x_ray_dir)
		player->x_delta_dist = 1e10; //(1/0) = 1e10
	else
		player->x_delta_dist = fabs(1 / player->x_ray_dir);
	if (!player->y_ray_dir)
		player->y_delta_dist = 1e10;
	else
		player->y_delta_dist = fabs(1 / player->y_ray_dir);
	player->hit = 0;
}

void    init_rays(t_player  *player, int r)
{
    player->x_camera = 2 * r / (double)SCREEN_WIDTH - 1;
    player->x_ray_dir = player->xdir + player->x_plane + player->x_camera;
    player->y_ray_dir = player->ydir + player->y_plane + player->x_camera;
}

void    raycasting(t_player *player, t_vars *game)
{
    int r;

    r = 0;
    while (r < SCREEN_WIDTH)
    {
        init_rays(player, r);
        delta_dist(player, game);
        calc_rays(player, game);
        // dda_loop(player, game);
        r++;
    }
}