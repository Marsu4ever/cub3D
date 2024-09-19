/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/19 10:27:18 by stigkas          ###   ########.fr       */
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

int	pos_valid(t_vars *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	x = (int)game->pl->x_pos;
	y = (int)game->pl->y_pos;
	while (game->map[j])
		j++;
	if (j < y)
		return (0);
	while (game->map[y][i])
		i++;
	if (i < x)
		return (0);
	return (1);
}
