/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:39:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/15 12:01:31 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    create_floor_ceiling(t_vars *game)
{
    int x;
    int y;

    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            if (y < SCREEN_HEIGHT / 2)
                mlx_put_pixel(game->image, x, y, game->c_values);
            else
                mlx_put_pixel(game->image, x, y, game->f_values);
            x++;
        }
        y++;
    }
}

int	get_rgba(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

void	render(t_vars *game)
{
	int32_t length;

	length = game->image->height * game->image->width * sizeof(int32_t);
	ft_memset(game->image->pixels, 0, length);
	// game->c_values = get_rgba(225, 30, 0);
    // game->f_values = get_rgba(200, 100, 0);
    create_floor_ceiling(game);
    raycasting(game->player, game);
}

