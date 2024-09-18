/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_move_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:53:36 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 17:12:58 by mkorpela         ###   ########.fr       */
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
