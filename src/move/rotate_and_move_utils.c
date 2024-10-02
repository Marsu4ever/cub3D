/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_move_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:53:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/02 11:22:11 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	rotate_left(t_vars *game)
{
	double	old_xdir;
	double	oldxplane;

	old_xdir = game->pl->xdir;
	game->pl->xdir = game->pl->xdir * cos(ROT) \
		- game->pl->ydir * sin(ROT);
	game->pl->ydir = game->pl->ydir * cos(ROT) \
		+ old_xdir * sin(ROT);
	oldxplane = game->pl->x_plane;
	game->pl->x_plane = game->pl->x_plane * cos(ROT) \
		- game->pl->y_plane * sin(ROT);
	game->pl->y_plane = game->pl->y_plane * cos(ROT) \
		+ oldxplane * sin(ROT);
}

void	rotate_right(t_vars *game)
{
	double	old_xdir;
	double	oldxplane;

	old_xdir = game->pl->xdir;
	game->pl->xdir = game->pl->xdir * cos(-ROT) \
		- game->pl->ydir * sin(-ROT);
	game->pl->ydir = game->pl->ydir * cos(-ROT) \
		+ old_xdir * sin(-ROT);
	oldxplane = game->pl->x_plane;
	game->pl->x_plane = game->pl->x_plane \
		* cos(-ROT) - game->pl->y_plane * sin(-ROT);
	game->pl->y_plane = game->pl->y_plane \
		* cos(-ROT) + oldxplane * sin(-ROT);
}
