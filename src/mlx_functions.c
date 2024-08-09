/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:02:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/09 11:40:28 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_hook(mlx_key_data_t keydata, void *game_from_key_hook)
{
	t_vars	*game;

	game = (t_vars *)game_from_key_hook;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		printf("Key Press: -------->\n");                         //Ray tracing 4 simos
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		printf("Key Press: <--------\n");							//Ray tracing
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		printf("Key Press: W\n");								//Ray tracing
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		printf("Key Press: S\n");								//Ray tracing
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		printf("Key Press: D\n");								//Ray tracing
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		printf("Key Press: A arrow\n");								//Ray tracing

	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		printf("Key Press: Right arrow\n");                         //Ray tracing 4 simos
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		printf("Key Press: Left arrow\n");							//Ray tracing
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		printf("Key Press: W arrow\n");								//Ray tracing
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		printf("Key Press: S arrow\n");								//Ray tracing
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		printf("Key Press: D arrow\n");								//Ray tracing
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		printf("Key Press: A arrow\n");			
		printf("Key Press: A\n");								//Ray tracing
}


void    mlx_functions(t_vars *game)
{
    game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Wolfenstein_3D", true);
	game->image = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->image)
	{
		mlx_close_window(game->mlx);
		msg_and_exit("No new image.\n", 2);
	}
	mlx_load_png("./textures/NO.png");
	mlx_load_png("./textures/EA.png");
	mlx_load_png("./textures/SO.png");
	mlx_load_png("./textures/WE.png");
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		msg_and_exit("Image to window failed.\n", 2);
	}
	mlx_loop_hook(game->mlx, (void *)render, game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
