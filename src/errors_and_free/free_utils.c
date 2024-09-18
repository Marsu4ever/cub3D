/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:29:04 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 14:35:34 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_all(t_vars *game)
{
	if (game->file != NULL)
	{
		free_array(game->file);
	}
	if (game->map != NULL)
	{
		free_array(game->map);
	}
	if (game->pl->ray != NULL)
	{
		free(game->pl->ray);
		game->pl->ray = NULL;
	}
	if (game->pl != NULL)
	{
		free(game->pl);
		game->pl = NULL;
	}
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

void	free_incomplete_array(char **array, int i)
{
	i--;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
