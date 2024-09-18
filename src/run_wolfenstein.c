/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wolfenstein.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:02:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 13:50:18 by mkorpela         ###   ########.fr       */
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
		rotate_right(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate_left(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_w(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_s(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_d(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_a(game);
	move_repeat(keydata, game);
}

void	move_repeat(mlx_key_data_t keydata, void *game)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		rotate_right(game);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		rotate_left(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_w(game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		move_s(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		move_d(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		move_a(game);
}

void	run_wolfenstein(t_vars *game)
{
	game->mlx = mlx_init(SCREEN_W, SCREEN_H, "WolfenTeam 3D", true);
	if (game->mlx == NULL)
		error_msg_and_exit(MLX_INIT_FAIL, "game->mlx", game);
	game->image = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!game->image)
		error_msg_and_exit(MLX_NEW_IMAGE_FAIL, "game->image", game);
	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
		error_msg_and_exit(MLX_IMG_TO_WINDOW_FAIL, NULL, game);
	if (mlx_loop_hook(game->mlx, (void *)wall_slicing, game) != 1)
		error_msg_and_exit(MLX_LOOP_HOOK_FAIL, NULL, game);
	mlx_key_hook(game->mlx, move_hook, game);
	mlx_loop(game->mlx);
}
