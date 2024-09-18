/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:24:44 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 16:24:54 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	move_repeat(mlx_key_data_t keydata, void *game)
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
