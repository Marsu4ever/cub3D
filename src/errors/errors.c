/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:36:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/23 10:26:52 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	msg_and_exit(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(1);
}

// void	error_msg_and_exit(char	*msg, char *specifier, t_vars *game)
// {
// 	ft_putstr_fd("Error\n", 2);
// 	ft_putstr_fd(msg, 2);
// 	if (specifier != NULL)
// 	{
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(specifier, 2);
// 	}
// 	ft_putstr_fd("\n", 2);
// 	if (game != NULL)
// 	{
// 		/*free and destroy*/
// 	}
// 	exit (1);
// } 

void	free_all(t_vars *game)
{
	if (game->map != NULL)
	{
		free_array(game->map);
	}
	if (game->map != NULL)
	{	
		free(game->player);
		game->player = NULL;
	}
	game = NULL;
}

void	destroy_textures(t_vars *game)
{
	if (game->north != NULL)
	{
		mlx_delete_texture(game->north);
		game->north = NULL;
	}
	if (game->south != NULL)
	{
		mlx_delete_texture(game->south);
		game->south = NULL;
	}
	if (game->east != NULL)
	{
		mlx_delete_texture(game->east);
		game->east = NULL;
	}
	if (game->west != NULL)
	{
		mlx_delete_texture(game->west);
		game->west = NULL;
	}
}

void	it_ends_here(t_vars *game)
{
	destroy_textures(game);
	// mlx_close_window(game->mlx); /*Do I need this function?*/
	// mlx_terminate(game->mlx);
	/*
		-destroy
			-textures
			-MLX
				-image
				-mlx
	*/
	free_all(game);
	exit(1);
	// game = NULL;
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
		/*
			free and destroy
		*/
		it_ends_here(game);
	}
	exit (1);
}
