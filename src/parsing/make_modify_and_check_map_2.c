/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modify_and_check_map_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:46:49 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 12:59:32 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	new_line_check(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n')
		{
			error_msg_and_exit(NEWLINE_IN_MAP, NULL, game);
		}
		i++;
	}	
}

static void	change_spaces_to_walls(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		character_replace(map[i], ' ', '1');
		i++;
	}
}

static void	change_new_lines_to_null_terminators(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		character_replace(map[i], '\n', '\0');
		i++;
	}
}

void	modify_map(char **map)
{
	change_spaces_to_walls(map);
	change_new_lines_to_null_terminators(map);
}
