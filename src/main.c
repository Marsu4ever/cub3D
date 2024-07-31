/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:57:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/31 14:44:08 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    minimal_mlx(t_game *game)
{
    game->mlx = mlx_init(960, 540, "cub3D", false); /*game_width = 1300 and  game_height = 900 - (fshields)*/
	game->image = mlx_new_image(game->mlx, 960, 540);
	mlx_load_png("./textures/NO.png");
	mlx_load_png("./textures/EA.png");
	mlx_load_png("./textures/SO.png");
	mlx_load_png("./textures/WE.png");
	mlx_image_to_window(game->mlx, game->image, 0, 0);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

static void make_map(t_game *game, int num_of_rows_in_map, char **argv)
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


void calc_and_make_map(t_game *game, char **av)
{
	int	num_of_rows;
	
	num_of_rows = number_of_rows_in_map(av);
	make_map(game, num_of_rows, av);
}

int main (int ac, char **av)
{
    t_game  game;
    
	game = (t_game){0};
    if (ac != 2)
        msg_and_exit("Please use only two arguments!!");
    else
    {
        calc_and_make_map(&game, av);
		minimal_mlx(&game);
        //something
    }
}
