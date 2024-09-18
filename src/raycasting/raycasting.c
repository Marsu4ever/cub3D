/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:09:17 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 13:16:08 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	dda_loop(t_player *pl, t_vars *game)
{
	while (pl->hit == 0)
	{
		if (pl->ray->xside_d < pl->ray->yside_d)
		{
			pl->ray->xside_d += delta_d(pl->ray->x_rdir);
			game->x_map += pl->x_step;
			pl->ray->side = 0;
		}
		else
		{
			pl->ray->yside_d += delta_d(pl->ray->y_rdir);
			game->y_map += pl->y_step;
			pl->ray->side = 1;
		}
		if (game->map[game->y_map][game->x_map] == '1' && pos_valid(game) == 1)
			pl->hit = 1;
	}
}

void	get_ray(t_player *pl)
{
	pl->ray->side = -1;
	if (pl->ray->x_rdir >= 0)
	{
		pl->x_step = 1;
		pl->ray->xside_d = ((int)pl->x_pos + 1.0 - pl->x_pos) \
			* delta_d(pl->ray->x_rdir);
	}
	else
	{
		pl->x_step = -1;
		pl->ray->xside_d = (pl->x_pos - (int)pl->x_pos) \
			* delta_d(pl->ray->x_rdir);
	}
	if (pl->ray->y_rdir >= 0)
	{
		pl->y_step = 1;
		pl->ray->yside_d = ((int)pl->y_pos + 1.0 - pl->y_pos) \
			* delta_d(pl->ray->y_rdir);
	}
	else
	{
		pl->y_step = -1;
		pl->ray->yside_d = (pl->y_pos - (int)pl->y_pos) \
			* delta_d(pl->ray->y_rdir);
	}
}

double	delta_d(double ray_dir)
{
	if (ray_dir != 0)
		return (fabs(1 / ray_dir));
	else
		return (1e10);
}

void	init_rays(t_player *pl, int r)
{
	pl->x_camera = 2 * r / (double)SCREEN_W - 1;
	pl->ray->x_rdir = pl->xdir + pl->x_plane * pl->x_camera;
	pl->ray->y_rdir = pl->ydir + pl->y_plane * pl->x_camera;
	if (fabs(pl->ray->x_rdir) < 1e-6)
		pl->ray->x_rdir = 1e-6;
	if (fabs(pl->ray->y_rdir) < 1e-6)
		pl->ray->y_rdir = 1e-6;
}

void	calc_rays(t_vars *game)
{
	game->pl->hit = 0;
	get_ray(game->pl);
	game->x_map = (int)game->pl->x_pos;
	game->y_map = (int)game->pl->y_pos;
	dda_loop(game->pl, game);
	if (game->pl->ray->side == 0)
		game->pl->ray->perp_wdist = game->pl->ray->xside_d \
			- delta_d(game->pl->ray->x_rdir);
	else
		game->pl->ray->perp_wdist = game->pl->ray->yside_d \
			- delta_d(game->pl->ray->y_rdir);
	game->pl->ray->wall_h = SCREEN_H / game->pl->ray->perp_wdist;
}
