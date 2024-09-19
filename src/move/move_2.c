/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:47:55 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/19 10:49:01 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

int	hit_a_wall(t_vars *game, double new_x, double new_y)
{
	double	newer_x;
	double	newer_y;

	if (game->pl->xdir > 0)
		newer_x = new_x + 0.2;
	else if (game->pl->xdir < 0)
		newer_x = new_x - 0.2;
	else
		newer_x = new_x;
	if (game->pl->ydir > 0)
		newer_y = new_y + 0.2;
	else if (game->pl->ydir < 0)
		newer_y = new_y - 0.2;
	else
		newer_y = new_y;
	if ((game->map[(int)new_y][(int)new_x] == '1') \
		|| (game->map[(int)newer_y][(int)newer_x] == '1'))
		return (1);
	return (0);
}
