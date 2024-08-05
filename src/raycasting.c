/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:09:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/03 00:30:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void hit_check(t_player *player, t_vars *game)
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

void    calc_the_rays(t_player  *player, int r)
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
        calc_the_rays(player, r);
        hit_check(player, game);
        r++;
    }
}