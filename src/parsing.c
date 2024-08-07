/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:47:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/06 13:56:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	error_msg_and_exit(char	*msg, char *specifier)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (specifier != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(specifier, 2);
	}
	ft_putstr_fd("\n", 2);
	/*free and destroy*/
	exit (1);
}

void	check_argument_count(int ac)
{
	if (ac != 2)
	{		
		error_msg_and_exit("Pass in just ONE argument.", NULL);
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
		error_msg_and_exit("File name is too short.", NULL);
	}
	if (ft_strcmp(av + i - 4, ".cub") != 0)
	{
		error_msg_and_exit("File should end with .cub", NULL);
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
		error_msg_and_exit("Open function failed", strerror(errno));
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
	printf("line_count: %d\n", line_count);
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
		error_msg_and_exit("Open function failed", strerror(errno));
	}
	file = malloc(sizeof(char *) * (number_of_lines + 1));
	if (file == NULL)
	{
		close(fd);
		error_msg_and_exit("Malloc failed", "@ retrieve_whole_file");
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
	print_it(game->whole_file);
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
		error_msg_and_exit("Identifier missing", identifier);
	}
	if (identifier_count == 1)
	{
		return ;
	} 
	if (identifier_count >= 2)
	{
		error_msg_and_exit("Duplicates of identifier detected", identifier);
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
	if (line[i] == ' ')
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
		if (check_if_map(game->whole_file[i]) == true)
		{
			if (identifier_count == 6)
			{
				return ;
			}
			if (identifier_count < 6)
			{
				error_msg_and_exit("Map occurs before identifier in config file.", NULL);
			}
		}
		i++;
	}
	error_msg_and_exit("No map was found in config file.", NULL);
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
}

// int	find_value_start()
// {
// 	/*
// 		-ft_strlen(identifier)
// 		-ft_isspace
// 		-return (number)
// 	*/
// }

// void	extract_identifier_value(t_vars *game, char *identifier)
// {
// 	char	*value;
// 	int		value_start;
// 	int		i;

// 	i = 0;
// 	while (game->whole_file[i])
// 	{
// 		if (ft_strncmp(game->whole_file[i], identifier, ft_strlen(identifier)) == 0)
// 		{
// 			value_start = find_value_start(game->whole_file[i]);
// 			// ft_strdup();
// 		}
// 		i++;
// 	}
// }

void	extract_data_from_config_file(t_vars *game)
{
	game = NULL;
	// extract_identifier_value(game, "NO ");//Return a malloced line
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
	extract_data_from_config_file(game);
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
                    -check only digits [0-9] 
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
