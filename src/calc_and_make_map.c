/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_and_make_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:23:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/05 11:28:54 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

#include "cube3d.h"

static void make_map(t_vars *game, int num_of_rows_in_map, char **argv)
{
	int		fd;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (num_of_rows_in_map + 1));
	if (map == NULL)
		exit (1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile didn't open. ", 2);
		ft_putstr_fd("Was it perchance a misspelt file you added there?\n", 2);
		exit (1);
	}
	i = 0;
	while (i < num_of_rows_in_map)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			// free_incomplete_map_and_exit(map, i);
		i++;
	}
	map[i] = NULL;
	close (fd);
	game->map = map;
}

static int	number_of_rows_in_map(char **argv)
{
	int		fd;
	int		num_of_rows_in_map;
	char	*string;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nFile didn't open. ", 2);
		ft_putstr_fd("Was it perchance a misspelt file you added there?\n", 2);
		exit (1);
	}
	num_of_rows_in_map = 0;
	string = "let's get into the while loop";
	while (string)
	{
		string = get_next_line(fd);
		// printf("%s", string);
		if (string)
			num_of_rows_in_map++;
		free (string);
	}
	close (fd);
	return (num_of_rows_in_map);
}


void calc_and_make_map(t_vars *game, char **av)
{
	int	num_of_rows;

	num_of_rows = number_of_rows_in_map(av);
	make_map(game, num_of_rows, av);
}