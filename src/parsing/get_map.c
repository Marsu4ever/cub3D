/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:02:19 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/13 13:06:23 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	new_line_check(t_vars *game, char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == '\n')
		{
			error_msg_and_exit("New_line character detected within map", NULL, game);
		}
		i++;
	}	
}

void	change_spaces_to_walls(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		character_replace(map[i], ' ', '1');
		i++;
	}
}

void	change_new_lines_to_null_terminators(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		character_replace(map[i], '\n', '\0');
		i++;
	}
}

void	is_there_invalid_character(t_vars *game, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0')
		{
			;
		}
		else if (line[i] == 'N' || line[i] == 'S')
		{
			;
		}
		else if (line[i] == 'W' || line[i] == 'E')
		{
			;
		}
		else
		{
			error_msg_and_exit("Map should only contain 0, 1, N, S, W, E or spaces", NULL, game);
		}
		i++;					
	}
}

void	check_for_invalid_character(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		is_there_invalid_character(game, map[i]);
		i++;
	}
}

int	count_chars(char *line, int character)
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

int	char_count_in_array(char **map, char character)
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
	player_count += char_count_in_array(map, 'N');//ALSO set the player into struct
	player_count += char_count_in_array(map, 'S');
	player_count += char_count_in_array(map, 'E');
	player_count += char_count_in_array(map, 'W');
	if (player_count == 0)
	{
		error_msg_and_exit("No player found on map", NULL, game);
	}
	if (player_count >= 2)
	{
		error_msg_and_exit("There should be ONLY one player on map", NULL, game);
	}
}

void	free_incomplete_array(char **array, int i)
{
	i--;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	array = NULL;
}

char	**make_map(t_vars *game, int start, int end)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (end - start + 1 + 1));
	if (map == NULL)
	{
		error_msg_and_exit("Malloc fail", "map", game);
	}
	i = 0;
	while (start <= end)
	{
		map[i] = ft_strdup(game->config_file[start]);
		if (map[i] == NULL)
		{
			free_incomplete_array(map, i);
			error_msg_and_exit("Malloc fail", "map[i]", game);
		}
		i++;
		start++;
	}
	map[i] = NULL;
	return (map);
}

int	get_index_end_of_map(t_vars *game, int start)
{
	int	end;
	
	end = start;
	while (game->config_file[start])
	{
		if (ft_strchr(game->config_file[start], '1') != NULL)
		{
			end = start;
		}
		start++;
	}
	return (end);
}

int	get_index_start_of_map(t_vars *game)
{
	int	i;

	i = 0;
	while (game->config_file[i])
	{
		if (check_if_indicator(game->config_file[i]) == true)
		{
			;
		}
		else if (check_if_map(game->config_file[i]) == true)
		{
			return (i) ;
		}
		i++;
	}
	return (i);
}

char	**get_map(t_vars *game)
{
	int		start;
	int		end;
	char	**map;
	
	// printf("Get map\n");
	
	/*
		-get map function
	*/
	
	start = get_index_start_of_map(game);
	end = get_index_end_of_map(game, start);
	map = make_map(game, start, end); /*Consider putting into a struct here. It'll help with freeing.*/
	
	// print_it(map);
	
	new_line_check(game, map);

	/*
		-map_modificications
	*/

	change_spaces_to_walls(map);

	// printf("After change\n");
	// print_it(map);
	
	/*
		-map_checks
	*/

	change_new_lines_to_null_terminators(map);
	check_for_invalid_character(game, map);
	check_number_of_players(game, map);

	check_if_closed(game, map);
	return (map);

	
	//check_if_map...
	/*
		-get index start of map
		-get index end of map
			-new_line_check (in map) /
		-malloc
		-ft_strdup
	*/
	
	/*
		-Find Map - while loop
			-start
			-end
		-extract map
			-malloc
			-ft_strdup
		-check
			-New_line check	
		
		-change
			-spaces (' ') to walls ('1')
			-new_lines to null terminators
	
		-check
			-invalid characters
			-is there N,S,E,W
			-is map closed
				-flood fill???
				-alternative approach

		-check Whole_file_for_invalid characters...
		
		-free whole file...
	*/
}
