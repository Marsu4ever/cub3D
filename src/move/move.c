/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:34:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 17:02:41 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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

void	move_w(t_vars *game)
{
	double	new_xpos;
	double	new_ypos;

	new_xpos = game->pl->x_pos + game->pl->xdir * SPEED;
	new_ypos = game->pl->y_pos + game->pl->ydir * SPEED;
	if (hit_a_wall(game, new_xpos, new_ypos) == 1)
		return ;
	game->pl->x_pos = new_xpos;
	game->pl->y_pos = new_ypos;
}

void	move_d(t_vars *game)
{
	double	new_xpos;
	double	new_ypos;

	new_xpos = game->pl->x_pos + game->pl->x_plane * SPEED;
	new_ypos = game->pl->y_pos + game->pl->y_plane * SPEED;
	if (hit_a_wall(game, new_xpos, new_ypos) == 1)
		return ;
	game->pl->x_pos = new_xpos;
	game->pl->y_pos = new_ypos;
}

void	move_s(t_vars *game)
{
	double	new_xpos;
	double	new_ypos;

	new_xpos = game->pl->x_pos - game->pl->xdir * SPEED;
	new_ypos = game->pl->y_pos - game->pl->ydir * SPEED;
	if (hit_a_wall(game, new_xpos, new_ypos) == 1)
		return ;
	game->pl->x_pos = new_xpos;
	game->pl->y_pos = new_ypos;
}

void	move_a(t_vars *game)
{
	double	new_xpos;
	double	new_ypos;

	new_xpos = game->pl->x_pos - game->pl->x_plane * SPEED;
	new_ypos = game->pl->y_pos - game->pl->y_plane * SPEED;
	if (hit_a_wall(game, new_xpos, new_ypos) == 1)
		return ;
	game->pl->x_pos = new_xpos;
	game->pl->y_pos = new_ypos;
}
