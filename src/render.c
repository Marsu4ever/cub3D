/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/29 14:20:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    create_floor(int x, t_vars *game)
{
	int y;

	y = game->player->wall_slice_end;
    while (y < (SCREEN_HEIGHT - 1))
    {
        mlx_put_pixel(game->image, x, y, game->f_values);
        y++;
    }
}

void    create_ceiling(int x, t_vars *game)
{
	int i;
	int y;

	y = 0;
	i = game->player->wall_slice_start;
    while (y < i)
    {
        mlx_put_pixel(game->image, x, y, game->c_values);
        y++;
    }
}

void create_the_maze(int x, t_vars *game)
{
	create_floor(x, game);
	render_wall_slice(x, game->player, game); //something gets devided bt zero while it should not
    create_ceiling(x, game);
}

int	get_rgba(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}
