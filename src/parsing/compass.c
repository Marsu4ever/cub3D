/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:10:42 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/14 09:43:17 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void n_s_compass(t_player *player, double num, double nmro)
{
    player->xdir = 0.0;
    player->ydir = num;
    player->x_plane = nmro;
    player->y_plane = 0.0;
}

void e_w_compass(t_player * player, double num, double nmro)
{
    player->xdir = num;
    player->ydir = 0.0;
    player->x_plane = 0.0;
    player->y_plane = nmro;
}
