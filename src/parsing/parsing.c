/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:47:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/23 14:16:08 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// void	print_it(char **array) /*Delete this later -> this is only for confirming*/
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("row: %d: %s", i, array[i]);
// 		i++;
// 	}
// }

// char	search_for_player(char *line)
// {
// 	int		i;
// 	char	player;

// 	i = 0;
// 	player = '0';
// 	while (line[i])
// 	{
// 		if (line[i] == 'N')
// 		{
// 			player = 'N';
// 		}
// 		if (line[i] == 'S')
// 		{
// 			player = 'S';
// 		}
// 		if (line[i] == 'W')
// 		{
// 			player = 'W';
// 		}
// 		if (line[i] == 'E')
// 		{
// 			player = 'E';
// 		}					
// 		i++;
// 	}
// 	return (player);
// }

// char	get_player_start_direction(t_vars *game)
// {
// 	char	player_direction;
// 	int		i;

// 	i = 0;
// 	player_direction = '0';
// 	while (game->map[i])
// 	{
// 		player_direction = search_for_player(game->map[i]);
// 		if (player_direction != '0')
// 		{
// 			return (player_direction);
// 		}
// 		i++;
// 	}
// 	return (player_direction);
// }

// int	get_player_start_x(t_vars *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j] != '\0')
// 		{
// 			if (game->map[i][j] == game->player_start_direction)
// 			{
// 				return (j);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

// int	get_player_start_y(t_vars *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while (game->map[i][j] != '\0')
// 		{
// 			if (game->map[i][j] == game->player_start_direction)
// 			{
// 				return (i);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

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
