/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wolfenstein.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:02:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/10 15:45:51 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/* uint32_t get_pixel_color(mlx_image_t* img, int x, int y)
{
    // Ensure the coordinates are within bounds
    if (x < 0 || x >= img->width || y < 0 || y >= img->height)
    {
        printf("out of bounds\n");
		return 0; // Return black or some default value for out-of-bounds access
    }

    // Calculate the pixel index in the buffer
    int pixel_index = (y * img->width + x) * 4;

    // Retrieve the color as a 32-bit integer (assuming 4 bytes per pixel - RGBA format)
    return *(uint32_t*)(&img->pixels[pixel_index]);
} */

// void	look_left(t_vars *game, int turn_angle)
// {
// 	game = NULL;
// 	turn_angle = 1;
	
	
	
// /* 	uint32_t	x2;
// 	uint32_t	y2;
// 	uint32_t	colour;
	
// 	uint32_t	x_old;
// 	int32_t		y_old;
// 	double 		x1;
// 	double 		y1;
//  */


// /* 	printf("%d\n", colour);
// 	if (game->minimap == NULL)
// 	{
// 		printf("game->minimap is NULL\n");
// 	}
// 	else
// 	{
// 		printf("game->minimap is NOT NULL\n");
// 	} */
	
// 	// y2 = 0;
// 	// while (y2 < 32)
// 	// {
// 	// 	x2 = 0;
// 	// 	while (x2 < 32)
// 	// 	{
// 	// 		// colour = *(uint32_t*)(&game->player_image->pixels[0]);
			
// 	// 		/*
// 	// 			-put in values
// 	// 		*/
// 	// 		x1 = x2 * cos(90 * PI / 180) - y2 * sin(90 * PI / 180);
// 	// 		printf("x1: %f\n", x1);
// 	// 		y1 = sin(90 * PI / 180)*x2 + y2*cos(90 * PI / 180);
// 	// 		printf("y1: %f\n", y1);
			
			
// 	// 		colour = get_pixel_color(game->player_image,x1, y1);
// 	// 		// colour = 255;
// 	// 		// printf("colour 1: %u\n", colour);
// 	// 		// colour = 4278190080;
// 	// 		// printf("colour 2: %u\n", colour);
// 	// 		mlx_put_pixel(game->player_image, x2, y2, colour);
// 	// 		// printf("j: %d\n", j);
// 	// 		x2++;
// 	// 	}
// 	// 	// printf("i: %d\n", i);
// 	// 	y2++;
// 	// }

	
// 	// mlx_put_pixel(game->minimap, 0, 0, 255);

// 	/*
// 		1. Change Raycasting values
// 		2. Rotate minimap player
		

// 			-SET NEW ANGLE

// 		-do some calculations so image rotates
// 			-axis of rotation - calculations
// 				-spend time working it out on paper???
// 				-keep track of angle in degrees?

// 				-put pixel with updated position
// 					-put pixel it???
// 						-HOW? 

				
// 		-job accomplished
// 	*/	
// }

// void	look_right(t_vars *game, int turn_angle)
// {
// 	game = NULL;
// 	turn_angle = 1;
// }

// void	move_up(t_vars *game, int move_distance)
// {
// 	/*
// 		-update position of player
// 			-on map???
// 				-I guess so... or somewhere else???
// 		-change starting tile to original -> actually player could just overlay... :)
// 		-
// 	*/

// /* 	printf("player_start_x: %d\n", game->player_start_x);
// 	printf("player_start_y: %d\n", game->player_start_y);
// 	printf("game->player->x_pos: %f\n", game->player->x_pos);
// 	printf("game->player->y_pos: %f\n", game->player->y_pos); */

	
// 	// game->player->y_pos--;

// 	// game->map[game->player->y_pos][game->player->x_pos];
// 	// game->player_image->instances[0].enabled = false;
// 	game->player_image->instances[0].y -= 1 * move_distance;
// }

// void	move_down(t_vars *game, int move_distance)
// {
// 	game->player_image->instances[0].y += 1 * move_distance;
// }

// void	move_left(t_vars *game, int move_distance)
// {
// 	game->player_image->instances[0].x -= 1 * move_distance;
// }

// void	move_right(t_vars *game, int move_distance)
// {
// 	game->player_image->instances[0].x += 1 * move_distance;
// }

// void	minimap_movement(t_vars *game, char direction)
// {
// 	int	move_distance;
// 	int	turn_angle;
	
// 	move_distance = 32;
// 	turn_angle = 15;
// 	if (direction == 'W')
// 		move_up(game, move_distance);
// 	if (direction == 'S')
// 		move_down(game, move_distance);
// 	if (direction == 'A')
// 		move_left(game, move_distance);
// 	if (direction == 'D')
// 		move_right(game, move_distance);
// 	if (direction == 'L')
// 		look_left(game, turn_angle);
// 	if (direction == 'R')
// 		look_right(game, turn_angle);
// }

void	move_hook(mlx_key_data_t keydata, void *game_from_key_hook)
{
	t_vars	*game;

	game = (t_vars *)game_from_key_hook;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		rotate_right(game);
		// printf("Key Press: -------->\n");
		// minimap_movement(game, 'R');
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		rotate_left(game);
		// printf("Key Press: <--------\n");			
		// minimap_movement(game, 'L');
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		move_w(game);
		// printf("Key Press: W\n");			
		// minimap_movement(game, 'W');
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		move_s(game);
		// printf("Key Press: S\n");			
		// minimap_movement(game, 'S');
	}	
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		move_d(game);
		// printf("Key Press: D\n");		
		// minimap_movement(game, 'D');
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		move_a(game);
		// printf("Key Press: A\n");			
		// minimap_movement(game, 'A');
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
	{
		rotate_right(game);
		// printf("Key Press: -------->\n");           
		// minimap_movement(game, 'R');
	}	
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
	{
		rotate_left(game);
		// printf("Key Press: <--------\n");				
		// minimap_movement(game, 'L');
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
	{
		move_w(game);
		// printf("Key Press: W\n");			
		// minimap_movement(game, 'W');
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
	{
		move_s(game);
		// printf("Key Press: S\n");				
		// minimap_movement(game, 'S');
	}	
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
	{
		move_d(game);
		// printf("Key Press: D\n");
		// minimap_movement(game, 'D');
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
	{
		move_a(game);
		// printf("Key Press: A\n");
		// minimap_movement(game, 'A');
	}
}

void	run_wolfenstein(t_vars *game)
{

	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Wolfenstein_3D", true);
	if (game->mlx == NULL)
		error_msg_and_exit(MLX_INIT_FAIL, "game->mlx", game);
	game->image = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->image)
		error_msg_and_exit(MLX_NEW_IMAGE_FAIL, "game->image", game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		error_msg_and_exit(MLX_IMG_TO_WINDOW_FAIL, NULL, game);
	// minimap(game);	
	if (mlx_loop_hook(game->mlx, (void *)wall_slicing, game) != 1)
		error_msg_and_exit(MLX_LOOP_HOOK_FAIL, NULL, game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
}
