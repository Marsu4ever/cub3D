/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:36:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/26 14:10:29 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	it_ends_here(t_vars *game)
{
	if (game->mlx != NULL)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
	destroy_textures(game);
	free_all(game);
	game = NULL;
	exit(1);
}

void	error_msg_and_exit(int error_number, char *where, t_vars *game)
{
	ft_putstr_fd("Error\n", 2);
	error_msg_selector(error_number);
	if (where != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(where, 2);
	}
	ft_putstr_fd("\n", 2);
	if (game != NULL)
	{
		it_ends_here(game);
	}
	exit (1);
}
