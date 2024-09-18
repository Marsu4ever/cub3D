/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:53:40 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 11:55:09 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cube3d.h"

// void	put_background(t_vars *game)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
	
// 	// printf("game->f_values: %d\n", game->f_values);
// 	// printf("game->c_values: %d\n", game->c_values);
// 	while (y < SCREEN_HEIGHT/2)
// 	{
// 		x = 0;
// 		while (x < SCREEN_WIDTH/2)
// 		{
// 			mlx_put_pixel(game->minimap, x, y, 255);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	put_pixel_in_tile(mlx_image_t *image)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
	
// 	// printf("game->f_values: %d\n", game->f_values);
// 	// printf("game->c_values: %d\n", game->c_values);
// 	while (y < 32)
// 	{
// 		x = 0;
// 		while (x < 32)
// 		{
// 			mlx_put_pixel(image, x, y, 255);
// 			x++;
// 		}
// 		y++;
// 	}
// }


// int	find_colour(t_vars *game, int x, int y)
// {
// 	/*
// 		1. Find angle
// 		2. Find pixel 
// 			-x(new) -> x(old)
// 			-y(new) -> y(old)
			
// 	*/
	
// 	game->player_degrees = 90;
// 	x = 0;
// 	y = 0;

// 	return (0);
// }

// void    rotate(t_vars *game)
// {
// 	int	x;
// 	int	y;
//     int colour;

// 	y = 0;
	
// 	// printf("game->f_values: %d\n", game->f_values);
// 	// printf("game->c_values: %d\n", game->c_values);
// 	while (y < 32)
// 	{
// 		x = 0;
// 		while (x < 32)
// 		{
// 			colour = find_colour(game, x, y);
//             mlx_put_pixel(game->player_image, x, y, 255);//Put colour in 255
// 			x++;
// 		}
// 		y++;
// 	}  
// }

// int	length_of_longest_row(char **map)
// {
// 	int	i;
// 	int	row_len;
// 	int	max_len;

// 	i = 0;
// 	max_len = 0;
// 	while (map[i])
// 	{
// 		row_len = ft_strlen(map[i]);
// 		if (row_len > max_len)
// 		{
// 			max_len = row_len;
// 		}
// 		i++;
// 	}
// 	return (max_len);
// }

// mlx_image_t	*image_selector(t_vars *game, int x, int y)
// {
// 	// tile = NULL;
// 	if (game->map[y][x] == '1')
// 	{
// 		return (game->wall);
// 	}
// 	if (game->map[y][x] == '0')
// 	{
// 		return (game->floor);
// 	}	
// 	if (game->map[y][x] == 'N' || game->map[y][x] == 'S' || game->map[y][x] == 'W' || game->map[y][x] == 'E')
// 	{
// 		return (game->player_image);
// 	}
// 	return (NULL);
// }

// void	put_all_tiles(t_vars *game, int map_height, int map_width)
// {
// 	/*
// 		-figure out square size
// 	*/
// 	/*
// 		-pass in walls
// 		-pass in floor
// 		-pass in character
// 	*/

// 	int	x;
// 	int	y;

// 	mlx_image_t	*tile;

// 	y = 0;
// 	while (y < map_height)
// 	{
// 		// printf("LOL\n");
// 		x = 0;
		
// 		while (x < map_width)
// 		{
// 			tile = image_selector(game, x, y);
// 			if (tile != NULL)
// 			{
// 				mlx_image_to_window(game->mlx, tile, x * 32, y * 32);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	// return (game);
// }

// void	load_image_to_struct_floor(t_vars *game)
// {
// 	mlx_texture_t	*floor;

// 	floor = mlx_load_png("./tiles/floor1.png");
// 	if (floor == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to load grass png.\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	game->floor = mlx_texture_to_image(game->mlx, floor);
// 	if (game->floor == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to convert grass texture to image.\n", 2);
// 		// mlx_delete_texture(grass);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	mlx_delete_texture(floor);
// 	if (mlx_resize_image(game->floor, 32, 32) == 0)
// 	{
// 		// ft_putstr_fd("Error\nFailed to resize image (@grass_load).\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// }

// void	load_image_to_struct_wall(t_vars *game)
// {
// 	mlx_texture_t	*wall;

// 	wall = mlx_load_png("./tiles/wall.png");
// 	if (wall == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to load grass png.\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	game->wall = mlx_texture_to_image(game->mlx, wall);
// 	if (game->wall == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to convert grass texture to image.\n", 2);
// 		// mlx_delete_texture(grass);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	mlx_delete_texture(wall);
// 	if (mlx_resize_image(game->wall, 32, 32) == 0)
// 	{
// 		// ft_putstr_fd("Error\nFailed to resize image (@grass_load).\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// }

// void	load_image_to_struct_player_image(t_vars *game)
// {
// 	mlx_texture_t	*player_image;

// 	player_image = mlx_load_png("./tiles/player1.png");
// 	if (player_image == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to load grass png.\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	game->player_image = mlx_texture_to_image(game->mlx, player_image);
// 	if (game->player_image == NULL)
// 	{
// 		// ft_putstr_fd("Error\nFailed to convert grass texture to image.\n", 2);
// 		// mlx_delete_texture(grass);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// 	mlx_delete_texture(player_image);
// 	if (mlx_resize_image(game->player_image, 32, 32) == 0)
// 	{
// 		// ft_putstr_fd("Error\nFailed to resize image (@grass_load).\n", 2);
// 		// free_map_structs_and_images_and_then_exit(game);
// 	}
// }

// int	calc_tile_length(int map_height, int map_width)
// {
// 	int	tile_width;
// 	int	tile_height;

// 	tile_width = SCREEN_WIDTH/2 / map_width;
// 	tile_height = SCREEN_HEIGHT/2 / map_height;

// 	if (tile_width > tile_height)
// 	{
// 		return (tile_height);
// 	}
// 	else
// 	{
// 		return (tile_width);
// 	}
// }


// /*
// 	Do I need to calculate the area of the image???

// 	-load images...
// 		-texture -> image
	
	
// 	-image selector
// */

// void	show_me_your_tile(t_vars *game, char tile_char)
// {
// 	int	x;
// 	int	y;

// 	mlx_image_t	*tile;

// 	if (tile_char == '1')
// 	{
// 		tile = game->wall;
// 	}
// 	else if (tile_char == '0')
// 	{
// 		tile = game->floor;
// 	}
// 	else
// 	{
// 		tile = game->player_image;
// 	}
// 	y = 0;
// 	while (game->map[y] != NULL)
// 	{
// 		x = 0;
// 		while (game->map[y][x] != '\0') 
// 		{
// 			if (game->map[y][x] == tile_char)
// 			{
// 				if (game->map[y][x] != '0' && game->map[y][x] != '1')
// 				{
// 					mlx_image_to_window(game->mlx, game->floor, x * 32, y * 32);
// 				}
// 				mlx_image_to_window(game->mlx, tile, x * 32, y * 32);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	put_in_tiles(t_vars *game)
// {
// 	show_me_your_tile(game, '1');
// 	show_me_your_tile(game, '0');
// 	show_me_your_tile(game, game->player_start_direction);
// }

// void	put_tiles(t_vars *game)
// {
// 	load_image_to_struct_wall(game); //This essentially is a hardcode
// 	load_image_to_struct_floor(game);
// 	load_image_to_struct_player_image(game);
// 	put_in_tiles(game);
// }

// void	minimap(t_vars *game)
// {
// 	game->minimap = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	mlx_image_to_window(game->mlx, game->minimap, 0, 0);
//         // put_background(game);

// 	put_tiles(game);
	
//     // rotate(game);
//     // put_pixel_in_tile(game->player_image);
    
// /*
// 	Minimap
// 		-image to window
// 			-to LHS corner (and small)
// 		-add
// 			-add individual tiles [walls and floor]
// 			-add player
// 		-function to rotate image
// */

// }
