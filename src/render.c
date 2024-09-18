/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 13:18:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	create_ceiling(int x, t_vars *game)
{
	int	y;

	y = game->pl->w_end;
	while (y <= (SCREEN_H - 1))
	{
		mlx_put_pixel(game->image, x, y, game->c_values);
		y++;
	}
}

void	create_floor(int x, t_vars *game)
{
	int	y;

	y = 0;
	while (y < game->pl->w_start)
	{
		mlx_put_pixel(game->image, x, y, game->f_values);
		y++;
	}
}

void	create_the_maze(int x, t_vars *game)
{
	create_ceiling(x, game);
	render_wall_slice(x, game->pl, game);
	create_floor(x, game);
}

int	get_rgba(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
