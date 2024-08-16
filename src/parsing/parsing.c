/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:47:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/16 14:01:33 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_it(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("row: %d: %s", i, array[i]);
		i++;
	}
}

void	error_check_texture_string(t_vars *game, char *value, char *identifier)
{
	int	i;

	i = ft_strlen(value);
	if (i < 5)
	{
		free(value);
		error_msg_and_exit(TEXTURE_TOO_SHORT, identifier, NULL);
	}	
	if (ft_strcmp(&value[i - 4], ".png") != 0)
	{
		free(value);
		error_msg_and_exit(TEXTURE_NO_END_PNG, identifier, game);
	}
	if (ft_strcmp(&value[i - 5], "/.png") == 0)
	{
		free(value);
		error_msg_and_exit(HIDDEN_FILE_PNG, identifier, game);
	}	
	// if (ft_strcmp(&av[i - 5], "/.cub") == 0)
	// {
	// 	error_msg_and_exit(HIDDEN_FILE, NULL, NULL);
	// }
}

mlx_texture_t	*get_texture(t_vars *game, char *identifier)
{
	char			*value;
	int				value_start;
	int				i;
	mlx_texture_t	*texture;

	i = get_element_index(game, identifier);
	value_start = get_identifier_start(game->config_file[i], identifier);
	// printf("original line: %s", game->config_file[i]);
	value = parse_out_key_and_spaces(game->config_file[i], value_start);
	// printf("value of original line: %s", value);
	value = character_replace(value, '\n', '\0');

	error_check_texture_string(game, value, identifier);
	// check_if_hidden_file(game, value, identifier);
	/*

		-check .png
		-check if hidden file

	*/

	// printf("value of original line without nl: %s\n", value);
	texture = mlx_load_png(value);
	free(value);
	if (texture == NULL)
	{
		error_msg_and_exit(LOAD_PNG_FAIL, identifier, NULL);
	}
	return (texture);
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
	char	player_direction;
	int		i;

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
	while (game->map[i])
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
	while (game->map[i])
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

/*
	-check if indicator
	-check if map
	-check if (spaces/tabs + newline)
	-otherwise error
*/

void	get_and_check_data(t_vars *game)
{
	game->north = get_texture(game, "NO ");	//Refactor this function [I do not like while_loops]
	game->south = get_texture(game, "SO ");
	game->east = get_texture(game, "EA ");
	game->west = get_texture(game, "WE ");
	game->f_values = get_colour(game, "F ");//Refactor this function [I vote against whileloops]
	game->c_values = get_colour(game, "C ");
	modify_and_check_map(game);
	find_player_position(game); /*Set player orientation???*/
	// check_for_errors_in_config_file(game);
	free_array(game->config_file);

	/*
		game->player_start_direction = get_player_start_direction(game);
		game->player_start_x = get_player_start_x(game); 	//I don't need these.
		game->player_start_y = get_player_start_y(game);	//I don't need these.
		printf("game->player_start_x: %d\n", game->player_start_x);
		printf("game->player_start_y: %d\n", game->player_start_y);
	\*/

	// printf("game->player_start_direction: %c\n", game->player_start_direction);
	/*
		-set player direction
	*/
}

void	parsing(t_vars *game, int ac, char **av)
{
	check_user_input(ac, av[1]);
	read_file(game, av[1]);
	check_file(game);
	get_and_check_data(game);
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
