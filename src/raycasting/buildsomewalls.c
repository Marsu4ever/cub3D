/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildsomewalls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:54:37 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/19 10:37:52 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

uint32_t	paint_wslice(t_player *player, t_vars *game, int x, uint32_t *pixar)
{
	uint32_t	paint;
	int			y;
	int			i;

	y = player->y_texture;
	i = y * game->texture->width + x * (int)game->texture->bytes_per_pixel;
	if (i < 0 || i >= (int)(game->texture->width * game->texture->height))
		return (0);
	paint = pixar[i];
	return (paint);
}

int	x_texture(t_vars *game)
{
	if (game->pl->ray->side == 1)
		game->hit_pos = game->pl->x_pos + game->pl->ray->perp_wdist * \
			game->pl->ray->x_rdir;
	else
		game->hit_pos = game->pl->y_pos + game->pl->ray->perp_wdist * \
			game->pl->ray->y_rdir;
	game->hit_pos -= (floor)(game->hit_pos);
	game->pl->x_tex = (int)((game->hit_pos / 2) * (double)TEXTURE_W);
	if (game->pl->x_tex < 0)
		game->pl->x_tex = 0;
	if (game->pl->x_tex >= (int)TEXTURE_W)
		game->pl->x_tex = (int)TEXTURE_W - 1;
	return (game->pl->x_tex);
}

mlx_texture_t	*texture_pick(t_vars *game)
{
	if (game->pl->ray->side == 1)
	{
		if (game->pl->ray->y_rdir < 0)
			game->texture = game->south;
		else if (game->pl->ray->y_rdir > 0)
			game->texture = game->north;
	}
	else if (game->pl->ray->side == 0)
	{
		if (game->pl->ray->x_rdir > 0)
			game->texture = game->east;
		else if (game->pl->ray->x_rdir < 0)
			game->texture = game->west;
	}
	return (game->texture);
}

void	render_wall_slice(int x, t_player *player, t_vars *game)
{
	int		i;
	int		x_text;
	double	j;
	double	pos_tex;

	i = player->w_start;
	game->texture = texture_pick(game);
	x_text = x_texture(game);
	j = TEXTURE_H / player->ray->wall_h;
	pos_tex = (i - (SCREEN_H / 2 - player->ray->wall_h / 2)) * j;
	while (i < player->w_end)
	{
		player->y_texture = (int)pos_tex;
		if (game->pl->y_texture < 0)
			game->pl->y_texture = 0;
		if (game->pl->y_texture >= (int)TEXTURE_H)
			game->pl->y_texture = (int)TEXTURE_H - 1;
		pos_tex += j;
		game->paint = paint_wslice(player, game, x_text, \
			(uint32_t *)game->texture->pixels);
		game->paint = (game->paint << 24) | (((game->paint >> 16) << 24) >> 16) \
			| (((game->paint << 16) >> 24) << 16) | (game->paint >> 24);
		mlx_put_pixel(game->image, x, i, game->paint);
		i++;
	}
}

void	wall_slicing(t_vars *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		init_rays(game->pl, x);
		calc_rays(game);
		game->pl->w_start = SCREEN_H / 2 - game->pl->ray->wall_h / 2;
		if (game->pl->w_start < 0)
			game->pl->w_start = 0;
		game->pl->w_end = game->pl->ray->wall_h / 2 + SCREEN_H / 2;
		if (game->pl->w_end >= SCREEN_H)
			game->pl->w_end = SCREEN_H - 1;
		create_the_maze(x, game);
		x++;
	}
}
