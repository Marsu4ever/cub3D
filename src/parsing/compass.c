/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:10:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/18 14:07:12 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	n_s_compass(t_player *player, double num, double nmro)
{
	player->xdir = 0.0;
	player->ydir = num;
	player->x_plane = nmro;
	player->y_plane = 0.0;
}

void	e_w_compass(t_player *player, double num, double nmro)
{
	player->xdir = num;
	player->ydir = 0.0;
	player->x_plane = 0.0;
	player->y_plane = nmro;
}
