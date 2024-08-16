/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_closed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:52:18 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/15 12:58:50 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	must_have_at_least_3_rows(t_vars *game, int row_count)
{
	if (row_count <= 2)
	{
		error_msg_and_exit(MAP_TOO_FEW_ROWS, NULL, game);
	}
}

void	check_top(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
		{
			error_msg_and_exit(MAP_NOT_CLOSED, "Check Top", game);
		}
		i++;
	}
}

void	check_bottom(t_vars *game, char **map, int row_count)
{
	int	i;
	int	last_row;

	last_row = row_count - 1;
	i = 0;
	while (map[last_row][i])
	{
		if (map[last_row][i] != '1')
		{
			error_msg_and_exit(MAP_NOT_CLOSED, "Check Bottom", game);
		}
		i++;
	}
}

void	check_left(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
		{
			error_msg_and_exit(MAP_NOT_CLOSED, "Check Left", game);
		}
		i++;
	}
}

void	check_if_closed(t_vars *game, char **map)
{
	int	row_count;

	row_count = count_map_rows(map);
	// printf("row_count: %d\n", row_count);
	must_have_at_least_3_rows(game, row_count);
	check_top(game, map);
	check_bottom(game, map, row_count);
	check_left(game, map);
	check_right(game, map, row_count);
}
