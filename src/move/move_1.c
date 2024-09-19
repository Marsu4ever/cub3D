/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:34:41 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/19 10:48:55 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
