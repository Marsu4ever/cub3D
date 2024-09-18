/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wolfenstein.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:02:05 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 16:42:32 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

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
