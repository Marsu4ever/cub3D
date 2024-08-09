/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildsomewalls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:47:37 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/09 16:47:37 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void init_walls(t_player *player)
{
    player->wall_height = (int)(SCREEN_HEIGHT / player->perp_wall_dist);
    player->start_of_wall = (SCREEN_HEIGHT - player->wall_height) / 2;
    if (player->start_of_wall < 0)
        player->start_of_wall = 0;
    player->end_of_wall = (player->wall_height + SCREEN_HEIGHT)/2;
    if (player->end_of_wall > SCREEN_HEIGHT)
        player->end_of_wall = SCREEN_HEIGHT - 1;
}