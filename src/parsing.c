/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:47:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/12 09:55:25 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
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

void	error_msg_and_exit(char	*msg, char *specifier, t_vars *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (specifier != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(specifier, 2);
	}
	ft_putstr_fd("\n", 2);
	if (game != NULL)
	{
		/*free and destroy*/
	}
	exit (1);
}

void	check_argument_count(int ac)
{
	if (ac != 2)
	{		
		error_msg_and_exit("Pass in just ONE argument.", NULL, NULL);
	}
	return ;
}

void	check_file_extension(char *av)
{
	/*
		Edge cases
			map_name.cub
			./map_name.cub
			map.cub.cub 

		is it a directory???
	*/

	size_t	i;

	i = ft_strlen(av);
	if (i < 5)
	{
		error_msg_and_exit("File name is too short.", NULL, NULL);
	}
	if (ft_strcmp(av + i - 4, ".cub") != 0)
	{
		error_msg_and_exit("File should end with .cub", NULL, NULL);
	}
}

int	count_lines_in_file(char *av)
{
	int		fd;
	char	*line;
	int		line_count;
	int i;

	i = 0;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error_msg_and_exit("Open function failed", strerror(errno), NULL);
	}
	line_count = 0;
	line = "let's get into the while loop!";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		line_count++;
	}
	close (fd);
	// printf("line_count: %d\n", line_count);
	return (line_count);
}

char	**retrieve_whole_file(char *av, int number_of_lines)
{
	char	**file;
	int		i;
	int 	fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error_msg_and_exit("Open function failed", strerror(errno), NULL);
	}
	file = malloc(sizeof(char *) * (number_of_lines + 1));
	if (file == NULL)
	{
		close(fd);
		error_msg_and_exit("Malloc failed", "@ retrieve_whole_file", NULL);
	}
	i = 0;
	// printf("retrieve whole file\n");
	while (i < number_of_lines)
	{
		file[i] = get_next_line(fd);
		// printf("i: %d\n", i);
		// if (file[i])
		// {
		// 	printf("%s\n",  file[i]);
		// }
		i++;
		// printf("%s\n", file[i]);
	}
	file[i] = NULL;
	return (file);	
}

void	print_it(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("row: %d: %s", i,  array[i]);
		i++;
	}
}

void	read_whole_file(t_vars *game, char *av)
{
	/*
		-open file
		
		-count lines
		-whole file - malloc
	*/


	int	number_of_lines;


	number_of_lines = count_lines_in_file(av);
	game->whole_file = retrieve_whole_file(av, number_of_lines);
	// print_it(game->whole_file);
	/*
		-print whole map - function
	*/
	// if (fd == 0)
	game = NULL;
}

void	check_for_identifier(t_vars *game, char *identifier)
{
	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->whole_file[i])
	{
		if (ft_strncmp(game->whole_file[i], identifier, ft_strlen(identifier)) == 0)
		{
			identifier_count++;
		}
		i++;
	}
	// printf("identifier_count: %d\n", identifier_count);
	if (identifier_count == 0)
	{
		error_msg_and_exit("Identifier missing (or needs a separating space)", identifier, NULL);
	}
	if (identifier_count == 1)
	{
		return ;
	} 
	if (identifier_count >= 2)
	{
		error_msg_and_exit("Duplicates of identifier detected", identifier, NULL);
	} 
}

bool	check_if_identifier(char *line)
{
	char *identifiers[7] = {
		"NO ",
		"SO ",
		"EA ",
		"WE ",
		"C ",
		"F ",
		NULL
    };

	int	i;

	i = 0;
	while (identifiers[i] != NULL)
	{
		if (ft_strncmp(identifiers[i], line, ft_strlen(identifiers[i])) == 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_if_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])//Consider what spaces are...
	{
		if (line[i] == '1')
		{
			return (true);
		}
		i++;
	}
	return (false);
	// if (line[i] == '1' || line[i] == '0')
	// {
	// 	return (true);
	// }
	// if (line[i] == 'N' || line[i] == 'S')
	// {
	// 	return (true);
	// }
	// if (line[i] == 'W' || line[i] == 'E')
	// {
	// 	return (true);
	// }	
	// else
	// {
		
	// }
}

void	check_if_map_exists_and_is_last(t_vars *game)
{

	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->whole_file[i])
	{
		if (check_if_identifier(game->whole_file[i]) == true)
			identifier_count++;
		else if (check_if_map(game->whole_file[i]) == true)
		{
			if (identifier_count == 6)
			{
				return ;
			}
			if (identifier_count < 6)
			{
				error_msg_and_exit("Map occurs before identifier in config file.", NULL, NULL);
			}
		}
		i++;
	}
	error_msg_and_exit("No map was found in config file.", NULL, NULL);
}

void	check_config_file(t_vars *game)
{
	check_for_identifier(game, "NO ");
	check_for_identifier(game, "SO ");
	check_for_identifier(game, "WE ");
	check_for_identifier(game, "EA ");
	check_for_identifier(game, "F ");
	check_for_identifier(game, "C ");
	check_if_map_exists_and_is_last(game);
	/*
		-check for invalid input
			-
	*/
}

int	get_identifier_start(char *line, char *identifier_key)
{
	// char	*value;
	int		value_start;

	value_start = ft_strlen(identifier_key);
	if (line[value_start] == ' ')
	{
		value_start++;
	}
	return (value_start);
/* 	value = ft_strdup(&line[value_start]);
	if (value == NULL)
	{
		error_msg_and_exit("Malloc fail", identifier_key);
	}
	return (value); */
}

char	*character_replace(char	*line, char	char_initial, char char_final)
{
	int	i;
	
	if (char_initial == '\0')
	{
		return (line);
	}
	i = 0;	
	while (line[i] != '\0')
	{
		if (line[i] == char_initial)
		{
			line[i] = char_final;
		}
		i++;
	}
	return (line);
}

char	*parse_out_key_and_spaces(char *line, int value_start)
{
	char	*value;

	value = ft_strdup(&line[value_start]);
	if (value == NULL)
	{
		error_msg_and_exit("Malloc failed", "parse_out_key_and_spaces", NULL);
	}
	return (value);
	// modified_line = character_replace(modified_line, '\n', '\0');
	// return (modified_line);
}

mlx_texture_t	*get_texture(t_vars *game, char *identifier)
{
	char	*value;
	int		value_start;
	int		i;
	mlx_texture_t	*texture;

	i = 0;
	while (game->whole_file[i])
	{
		if (ft_strncmp(game->whole_file[i], identifier, ft_strlen(identifier)) == 0)
		{
			value_start = get_identifier_start(game->whole_file[i], identifier);
			// printf("original line: %s", game->whole_file[i]);
			value = parse_out_key_and_spaces(game->whole_file[i], value_start);
			// printf("value of original line: %s", value);
			value = character_replace(value, '\n', '\0');
			// printf("value of original line without nl: %s\n", value);
			texture = mlx_load_png(value);
			free(value);
			if (texture == NULL)
			{
				error_msg_and_exit("Check path for this identifier", identifier, NULL);
			}
			return (texture);
		}
		i++;
	}
	return (NULL);
}

void	check_if_only_digits_and_commas(t_vars *game, char	*value, char *identifier)
{
	int	i;

	i = 0;
	// printf("%s\n", value);
	while (value[i])
	{
		// printf("%c\n", value[i]);
		if ((value[i] >= '0' && value[i] <='9') || value[i] == ',')
		{
			;
		}
		else
		{
			free(value);
			error_msg_and_exit("Only digits[0-9] and commas are allowed - Check the following identifier", identifier, game);
		}
		i++;
	}
}

void	increment_index_when_digit(char *value, int *i)
{
	while (value[*i] >= '0' && value[*i] <= '9')
	{
		(*i)++;
	}
}

void	check_for_3_numbers_and_2_commas(t_vars *game, char	*value, char *identifier)
{
	int	number_count;
	int	comma_count;
	int	i;

	number_count = 0;
	comma_count = 0;
	i = 0;
	while (value[i])
	{
		if (value[i] >= '0' && value[i] <= '9')
		{
			increment_index_when_digit(value, &i);
			number_count++;
		}
		if (value[i] >= ',')
		{
			i++;
			comma_count++;
		}
	}
	// printf("number_count: %d\n", number_count);
	// printf("comma_count: %d\n", comma_count);
	if (number_count != 3 || comma_count != 2)
	{
		free(value);
		error_msg_and_exit("Numbers and commas must have format - [X,X,X]", identifier, game);
	}
}

int	check_range_and_get_colour_value(t_vars *game, char *value, char *identifier)
{
	int		rgb_numbers[3];
	char	**rgb_strings;
	int		i;
	int		number;
	
	rgb_strings = ft_split(value, ',');
	free(value);
	if (rgb_strings == NULL)
	{
		error_msg_and_exit("Malloc fail at ft_split", identifier, game);
	}
	i = 0;
	while (i < 3)
	{
		number = ft_atoi(rgb_strings[i]);
		if (number > 255 || number < 0)
		{
			free_array(rgb_strings);
			error_msg_and_exit("Numbers must have range of 0-255 - check identifier", identifier, game);
		}
		rgb_numbers[i] = number;
		i++;
	}
	free_array(rgb_strings);
	return (get_rgba(rgb_numbers[0], rgb_numbers[1], rgb_numbers[2]));
}

int	get_colour(t_vars *game, char *identifier)
{
	char	*value;
	int		value_start;
	int		i;
	int		colour_value;

	i = 0;
	colour_value = -1;
	while (game->whole_file[i])
	{
		if (ft_strncmp(game->whole_file[i], identifier, ft_strlen(identifier)) == 0)
		{
			value_start = get_identifier_start(game->whole_file[i], identifier);
			// printf("original line: %s", game->whole_file[i]);
			value = parse_out_key_and_spaces(game->whole_file[i], value_start);// Do I need this?
			value = character_replace(value, '\n', '\0');
			// printf("value of original line: %s\n", value);
			check_if_only_digits_and_commas(game, value, identifier);
			check_for_3_numbers_and_2_commas(game, value, identifier);
			colour_value = check_range_and_get_colour_value(game, value, identifier);
			break ;
		}
		i++;
	}
	return (colour_value);
}

bool	check_if_indicator(char *line)
{
	if (ft_strncmp(line, "NO ", ft_strlen("NO ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "SO ", ft_strlen("SO ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "WE ", ft_strlen("WE ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "EA ", ft_strlen("EA ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "F ", ft_strlen("F ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "C ", ft_strlen("C ")) == 0)
	{
		return (true);
	}
	return (false);		
}

int	get_index_start_of_map(t_vars *game)
{
	int	i;

	i = 0;
	while (game->whole_file[i])
	{
		if (check_if_indicator(game->whole_file[i]) == true)
		{
			;
		}
		else if (check_if_map(game->whole_file[i]) == true)
		{
			return (i) ;
		}
		i++;
	}
	return (i);
}

/* bool	check_if_map_2(char *line)
{
	int	i;

	i = 0;
	if (line[i] == ' ' )
	{
		i++;
	}
	if (line[i] == '1')
	{
		return (true);
	}
	else
	{
		return (false);
	}
} */

/*
	map ends with last 1
	
*/

// bool	is_there_a_one(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 1)
// 		{
// 			return (true);
// 		}
// 		i++;
// 	}
// 	return (false);
// }

int	get_index_end_of_map(t_vars *game, int start)
{
	int	end;
	
	end = start;
	while (game->whole_file[start])
	{
		if (ft_strchr(game->whole_file[start], '1') != NULL)
		{
			end = start;
		}
		start++;
	}
	return (end);
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
		map[i] = ft_strdup(game->whole_file[start]);
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

char	**get_map(t_vars *game)
{
	int		start;
	int		end;
	char	**map;
	
	// printf("Get map\n");
	start = get_index_start_of_map(game);
	/*
		-check for newlines in middle of map
			-if new_line at beginning of line
		-check map forward
	*/
	end = get_index_end_of_map(game, start);
	map = make_map(game, start, end);
	print_it(map);
	new_line_check(game, map);
	change_spaces_to_walls(map);
	change_new_lines_to_null_terminators(map);
	check_for_invalid_character(game, map);
	check_number_of_players(game, map);
	// int i;

	// i = 0;
	// while (map[i])
	// {
	// 	printf("map: %d: %s\n", i,  map[i]);
	// 	i++;
	// }	
	
	return (map);
	// print_it(map);
		
	
	/*
		make map
	*/	

	
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

char	search_for_player(char *line)
{
	int		i;
	char	player;

	i = 0;
	player = '0';
	while (line[i])
	{
		if (line[i] == 'N')
		{
			player = 'N';
		}
		if (line[i] == 'S')
		{
			player = 'S';
		}
		if (line[i] == 'W')
		{
			player = 'W';
		}
		if (line[i] == 'E')
		{
			player = 'E';
		}					
		i++;
	}
	return (player);
}

char	get_player_start_direction(t_vars *game)
{
	int	i;
	char	player_direction;

	i = 0;
	player_direction = '0';
	while (game->map[i])
	{
		player_direction = search_for_player(game->map[i]);
		if (player_direction != '0')
		{
			return (player_direction);
		}
		i++;
	}
	return (player_direction);
}

int	get_player_start_x(t_vars *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == game->player_start_direction)
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

int	get_player_start_y(t_vars *game)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == game->player_start_direction)
			{
				return (i);
			}
			j++;
		}
		i++;
	}
	return (-1);
}

void	check_and_extract_data_from_config_file(t_vars *game)
{
	game->north = get_texture(game, "NO ");		//Refactor this function [I do not like while_loops]
	game->south = get_texture(game, "SO ");
	game->east = get_texture(game, "EA ");
	game->west = get_texture(game, "WE ");
	game->f_values = get_colour(game, "F ");	//Refactor this function [I vote against whileloops]
	game->c_values = get_colour(game, "C ");
	game->map = get_map(game);
	game->player_start_direction = get_player_start_direction(game);
	game->player_start_x = get_player_start_x(game); 	//I don't need these.
	game->player_start_y = get_player_start_y(game);	//I don't need these.
	printf("game->player_start_x: %d\n", game->player_start_x);
	printf("game->player_start_y: %d\n", game->player_start_y);
	// printf("game->player_start_direction: %c\n", game->player_start_direction);
	/*
		-set player direction
	*/


	/* 
		-extract map
		-map check
			-change spaces (' ') to walls ('1')
			-new lines (within map)
			-(modify new lines at end to new line characters?)
			-invalid characters
			-is_map_closed?
			
			-check and extract
			-
		-free whole_file
	*/
	

	/*
		-free whole_file
	*/
}

void	parsing(t_vars *game, int ac, char **av)
{
	/*
		-check user input
	*/
	check_argument_count(ac);
	check_file_extension(av[1]);
	read_whole_file(game, av[1]);
	check_config_file(game);
	check_and_extract_data_from_config_file(game);
	/*
		-extract from config file
	*/


	
	/*
		-check for element
			-count how many
			-counter!!!
				-no_exist
				-duplicates
		-check_map_last in file
	*/

}


  /* 
        Idea for code structure

        -Parsing
            -check
                - number of arguments
                - .cub extension
            -read whole input file -> 2D array
                -check if elements present
                -Check order of assets... (check if map last)

            [LOTS OF CLEANING UP!] > maybe one step at a time

            -extract (raw) data
                -textures   (ft_strdup) (do not malloc identifier f.ex. EA)
                -colours    (ft_strdup)
					-(ft_atoi - do first)
                -map (raw)  

            -check for errors
                -textures
                    -valid path?
                        relative path - ./
                        absolute path - /
                    -is it a file? (not a directory)
                    -additional characters? - non printable???

                -colours
                    -check only digits [0-9] and commas
                    -3 numbers present
                        -ft_atoi
                            -numbers between 0-255
                                [->into struct]
                    -any other limitations?
                -map
                    -check for newlines?
                    -only valid chars?
                    
                    -parse spaces away from map [must] [also what are spaces = walls???]!
                        -check map
                            -is closed (walls surrounding) [Most work]
                        [->into struct]

            -init data struct
        

        -MLX functions
            -Ceiling and Floor
            -Raycasting

        -free and destroy textures
     */
