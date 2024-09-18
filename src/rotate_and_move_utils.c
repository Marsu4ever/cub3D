/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_move_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:53:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 13:12:22 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rotate_left(t_vars *game)
{
	double	old_xdir;
	double	oldxplane;

	old_xdir = game->pl->xdir;
	game->pl->xdir = game->pl->xdir * cos(rot) \
		- game->pl->ydir * sin(rot);
	game->pl->ydir = game->pl->ydir * cos(rot) \
		+ old_xdir * sin(rot);
	oldxplane = game->pl->x_plane;
	game->pl->x_plane = game->pl->x_plane * cos(rot) \
		- game->pl->y_plane * sin(rot);
	game->pl->y_plane = game->pl->y_plane * cos(rot) \
		+ oldxplane * sin(rot);
}

void	rotate_right(t_vars *game)
{
	double	old_xdir;
	double	oldxplane;

	old_xdir = game->pl->xdir;
	game->pl->xdir = game->pl->xdir * cos(-rot) \
		- game->pl->ydir * sin(-rot);
	game->pl->ydir = game->pl->ydir * cos(-rot) \
		+ old_xdir * sin(-rot);
	oldxplane = game->pl->x_plane;
	game->pl->x_plane = game->pl->x_plane \
		* cos(-rot) - game->pl->y_plane * sin(-rot);
	game->pl->y_plane = game->pl->y_plane \
		* cos(-rot) + oldxplane * sin(-rot);
}
