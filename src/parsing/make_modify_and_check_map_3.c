/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_modify_and_check_map_3.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:46:31 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 12:59:11 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	is_there_invalid_character(t_vars *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
		{
			i++;
		}
		else if (line[i] == 'N' || line[i] == 'S')
		{
			i++;
		}
		else if (line[i] == 'W' || line[i] == 'E')
		{
			i++;
		}
		else
		{
			error_msg_and_exit(INVALID_CHAR_IN_MAP, NULL, game);
		}					
	}
}

void	check_for_invalid_characters(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		is_there_invalid_character(game, map[i]);
		i++;
	}
}

static int	count_chars(char *line, int character)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == character)
		{
			count++;
		}
		i++;
	}
	return (count);
}

static int	char_count_in_array(char **map, char character)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += count_chars(map[i], character);
		i++;
	}
	return (count);
}

void	check_number_of_players(t_vars *game, char **map)
{
	int	player_count;

	player_count = 0;
	player_count += char_count_in_array(map, 'N');
	player_count += char_count_in_array(map, 'S');
	player_count += char_count_in_array(map, 'E');
	player_count += char_count_in_array(map, 'W');
	if (player_count == 0)
	{
		error_msg_and_exit(NO_PLAYER_FOUND, NULL, game);
	}
	if (player_count >= 2)
	{
		error_msg_and_exit(TOO_MANY_PLAYERS, NULL, game);
	}
}
