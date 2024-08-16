/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:36:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/16 14:48:01 by mkorpela         ###   ########.fr       */
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

void	error_msg_selector(int error)
{
	if (error == WRONG_ARG_COUNT)
	{
		ft_putstr_fd("Pass in just ONE argument.", 2);
	}
	if (error == FILE_TOO_SHORT)
	{
		ft_putstr_fd("Pass in a longer name for the file.", 2);
	}
	if (error == HIDDEN_FILE_CUB)
	{
		ft_putstr_fd(".cub [hidden] file does not have .cub extension.", 2);
	}
	if (error == FILE_NO_END_CUB)
	{
		ft_putstr_fd("You should pass in a file that ends with .cub", 2);
	}
	if (error == OPEN_FUNC_FAIL)
	{
		ft_putstr_fd("Open function failed", 2);
	}
	if (error == MALLOC_FAIL)
	{
		ft_putstr_fd("Malloc failed", 2);
	}
	if (error == NO_IDENTIFIER)
	{
		ft_putstr_fd("Identifier missing (or needs a separating space)", 2);
	}
	if (error == DUPLICATE_IDENTIFIER)
	{
		ft_putstr_fd("Duplicates of identifier detected", 2);
	}
	if (error == TEXTURE_TOO_SHORT)
	{
		ft_putstr_fd("Texture name is too short - check identifier", 2);
	}	
	if (error == TEXTURE_NO_END_PNG)
	{
		ft_putstr_fd("Texture should end with .png - check identifier", 2);
	}
	if (error == HIDDEN_FILE_PNG)
	{
		ft_putstr_fd(".png [hidden] file does not have .png extension.", 2);
	}
	if (error == LOAD_PNG_FAIL)
	{
		ft_putstr_fd("Check key value (in file) for this identifier", 2);
	}
	if (error == COLOUR_INVALID_CHAR)
	{
		ft_putstr_fd("Only digits[0-9] and commas are allowed - Check identifier", 2);/* Forgot this one!!!?!*/
	}
	if (error == COLOUR_INVALID_FORMAT)
	{
		ft_putstr_fd("Numbers and commas must have format - [X,X,X]", 2);
	}
	if (error == COLOUR_WRONG_RANGE)
	{
		ft_putstr_fd("Numbers must have range of 0-255 - check identifier", 2);
	}
	if (error == NEWLINE_IN_MAP)
	{
		ft_putstr_fd("Newline character detected within map", 2);
	}
	if (error == MAP_WRONG_PLACE)
	{
		ft_putstr_fd("Map occurs before identifier in config file.", 2);
	}
	if (error == MAP_NOT_FOUND)
	{
		ft_putstr_fd("No map was found in config file.", 2);
	}		
	if (error == INVALID_CHAR_IN_MAP)
	{
		ft_putstr_fd("Map should only contain 0, 1, N, S, W, E or spaces", 2);
	}
	if (error == NO_PLAYER_FOUND)
	{
		ft_putstr_fd("No player found on map", 2);
	}
	if (error == TOO_MANY_PLAYERS)
	{
		ft_putstr_fd("There should be ONLY one player on map", 2);
	}
	if (error == MAP_TOO_FEW_ROWS)
	{
		ft_putstr_fd("Map should have at least 3 rows to be closed", 2);
	}
	if (error == MAP_NOT_CLOSED)
	{
		ft_putstr_fd("Map is not closed (i.e. Use only ONEs (and spaces))", 2);
	}	
	if (error == INVALID_CHAR_IN_FILE)
	{
		ft_putstr_fd("Only newlines are accepted outside of elements and map.", 2);
	}
/* 	if (error == )
	{
		ft_putstr_fd("", 2);
	}
	if (error == )
	{
		ft_putstr_fd("", 2);
	}
	if (error == )
	{
		ft_putstr_fd("", 2);
	}		 */
}

void	free_all(t_vars *game)
{
	
	
	
	/*
		free
			**map
	*/
	
	free_array(game->map);
	free(game->player);
	game->player = NULL;

	/*
		
	*/
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

void	burn_baby_burn(t_vars *game)
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
}

void	error_msg_and_exit(int error_number, char *specifier, t_vars *game)
{
	ft_putstr_fd("Error\n", 2);
	error_msg_selector(error_number);
	if (specifier != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(specifier, 2);
	}
	ft_putstr_fd("\n", 2);
	if (game != NULL)
	{
		/*
			free and destroy
		*/
		burn_baby_burn(game);
	}
	exit (1);
}
