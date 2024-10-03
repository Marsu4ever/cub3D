/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_selector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 13:08:10 by mkorpela          #+#    #+#             */
/*   Updated: 2024/10/02 12:03:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	group_1_msgs(int error)
{
	if (error == WRONG_ARG_COUNT)
		ft_putstr_fd("Pass in just ONE argument.", 2);
	if (error == FILE_TOO_SHORT)
		ft_putstr_fd("Pass in a longer name for the file.", 2);
	if (error == HIDDEN_FILE_CUB)
		ft_putstr_fd(".cub [hidden] file does not have .cub extension.", 2);
	if (error == FILE_NO_END_CUB)
		ft_putstr_fd("You should pass in a file that ends with .cub", 2);
	if (error == OPEN_FUNC_FAIL)
		ft_putstr_fd("Open function failed", 2);
	if (error == MALLOC_FAIL)
		ft_putstr_fd("Malloc failed", 2);
}

static void	group_2_msgs(int error)
{
	if (error == NO_IDENTIFIER)
		ft_putstr_fd("Identifier missing (or needs a separating space)", 2);
	if (error == DUPLICATE_IDENTIFIER)
		ft_putstr_fd("Duplicates of identifier detected", 2);
	if (error == TEXTURE_TOO_SHORT)
		ft_putstr_fd("Texture name is too short - check identifier", 2);
	if (error == TEXTURE_NO_END_PNG)
		ft_putstr_fd("Texture should end with .png - check identifier", 2);
	if (error == HIDDEN_FILE_PNG)
		ft_putstr_fd(".png [hidden] file does not have .png extension.", 2);
	if (error == LOAD_PNG_FAIL)
		ft_putstr_fd("Error with this identifier", 2);
}

static void	group_3_msgs(int error)
{
	if (error == COLOUR_INVALID_CHAR)
	{
		ft_putstr_fd("Only digits[0-9] and commas are allowed", 2);
		ft_putstr_fd(" - Check identifier", 2);
	}
	if (error == COLOUR_INVALID_FORMAT)
		ft_putstr_fd("Numbers and commas must have format - [X,X,X]", 2);
	if (error == COLOUR_WRONG_RANGE)
		ft_putstr_fd("Numbers must have range of 0-255 - check identifier", 2);
	if (error == NEWLINE_IN_MAP)
		ft_putstr_fd("Newline character detected within map", 2);
	if (error == MAP_WRONG_PLACE)
		ft_putstr_fd("Map occurs before identifier in config file.", 2);
	if (error == MAP_NOT_FOUND)
		ft_putstr_fd("No map was found in config file.", 2);
}

static void	group_4_msgs(int error)
{
	if (error == INVALID_CHAR_IN_MAP)
		ft_putstr_fd("Map should only contain 0, 1, N, S, W, E and spaces", 2);
	if (error == NO_PLAYER_FOUND)
		ft_putstr_fd("No player found on map", 2);
	if (error == TOO_MANY_PLAYERS)
		ft_putstr_fd("There should be ONLY one player on map", 2);
	if (error == MAP_TOO_FEW_ROWS)
		ft_putstr_fd("Map should have at least 3 rows to be closed", 2);
	if (error == MAP_NOT_CLOSED)
		ft_putstr_fd("Map is not closed (i.e. Use only ONEs (and spaces))", 2);
	if (error == INVALID_CHAR_IN_FILE)
	{
		ft_putstr_fd("Only newlines are accepted outside", 2);
		ft_putstr_fd(" of elements and map.", 2);
	}
}

void	error_msg_selector(int error)
{
	group_1_msgs(error);
	group_2_msgs(error);
	group_3_msgs(error);
	group_4_msgs(error);
	if (error == MLX_INIT_FAIL)
		ft_putstr_fd("mlx_init fail", 2);
	if (error == MLX_NEW_IMAGE_FAIL)
		ft_putstr_fd("mlx_new_image fail", 2);
	if (error == MLX_IMG_TO_WINDOW_FAIL)
		ft_putstr_fd("mlx_image_to_window fail", 2);
	if (error == MLX_LOOP_HOOK_FAIL)
		ft_putstr_fd("mlx_loop_hook failed", 2);
}
