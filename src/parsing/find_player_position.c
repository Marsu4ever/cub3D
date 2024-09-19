/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:43 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/19 11:08:13 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void		set_player_direction(t_vars *game, char player_direction)
{
	if (player_direction == 'N')
		game->player_start_direction = 'N';
	if (player_direction == 'S')
		game->player_start_direction = 'S';
	if (player_direction == 'E')
		game->player_start_direction = 'E';
	if (player_direction == 'W')
		game->player_start_direction = 'W';
}

static void		orientation_calc(char compass, t_vars *game)
{
	if (compass == 'N')
		n_s_compass(game->pl, 1.0, FOV);
	else if (compass == 'E')
		e_w_compass(game->pl, 1.0, FOV);
	else if (compass == 'S')
		n_s_compass(game->pl, -1.0, -FOV);
	else if (compass == 'W')
		e_w_compass(game->pl, -1.0, -FOV);
}

static void		set_player_position(t_vars *game, char **map, int y)
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(map[y]) - 1)
	{
		if (map[y][j] == 'N' || map[y][j] == 'W' \
			|| map[y][j] == 'E' || map[y][j] == 'S')
		{
			set_player_direction(game, map[y][j]);
			orientation_calc(map[y][j], game);
			game->pl->x_pos = (double)j;
			game->pl->y_pos = (double)y;
		}
		j++;
	}
}

void	find_player_position(t_vars *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		set_player_position(game, game->map, i);
		i++;
	}
}
