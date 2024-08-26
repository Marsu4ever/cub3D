/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modify_and_check_map_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:33:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/23 15:59:53 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static char	**make_map(t_vars *game, int start, int end)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (end - start + 1 + 1));
	if (map == NULL)
	{
		error_msg_and_exit(MALLOC_FAIL, "map", game);
	}
	i = 0;
	while (start <= end)
	{
		map[i] = ft_strdup(game->file[start]);
		if (map[i] == NULL)
		{
			free_incomplete_array(map, i);
			error_msg_and_exit(MALLOC_FAIL, "map[i]", game);
		}
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

static int	get_index_start_of_map(t_vars *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (check_if_indicator(game->file[i]) == true)
		{
			i++;
		}
		else if (check_if_map(game->file[i]) == true)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static char	**get_map(t_vars *game)
{
	char	**map;
	int		start;
	int		end;

	start = get_index_start_of_map(game);
	end = get_index_end_of_map(game, start);
	map = make_map(game, start, end);
	return (map);
}

void	make_modify_and_check_map(t_vars *game)
{	
	game->map = get_map(game);
	new_line_check(game, game->map);
	modify_map(game->map);
	check_for_invalid_characters(game, game->map);
	check_number_of_players(game, game->map);
	check_if_closed(game, game->map);
}
