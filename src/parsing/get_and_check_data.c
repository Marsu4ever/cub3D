/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_and_check_data.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:42:33 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 13:42:02 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	error_check_texture_string(t_vars *game, char *value,
											char *identifier)
{
	int	i;

	i = ft_strlen(value);
	if (i < 5)
	{
		free(value);
		error_msg_and_exit(TEXTURE_TOO_SHORT, identifier, game);
	}	
	if (ft_strcmp(&value[i - 4], ".png") != 0)
	{
		free(value);
		error_msg_and_exit(TEXTURE_NO_END_PNG, identifier, game);
	}
	if (ft_strcmp(&value[i - 5], "/.png") == 0)
	{
		free(value);
		error_msg_and_exit(HIDDEN_FILE_PNG, identifier, game);
	}
}

static mlx_texture_t	*get_texture(t_vars *game, char *identifier)
{
	char			*path;
	int				path_start;
	int				i;
	mlx_texture_t	*texture;

	i = get_element_index(game, identifier);
	path_start = get_identifier_start(game->file[i], identifier);
	path = parse_out_key_and_spaces(game, game->file[i], path_start);
	path = character_replace(path, '\n', '\0');
	error_check_texture_string(game, path, identifier);
	texture = mlx_load_png(path);
	free(path);
	if (texture == NULL)
	{
		error_msg_and_exit(LOAD_PNG_FAIL, identifier, game);
	}
	return (texture);
}

static t_player	*init_player(t_vars *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error_msg_and_exit(MALLOC_FAIL, "Allocation of player failed.", game);
	player = (t_player *)ft_memset((void *)player, 0, sizeof(t_player));
	//ask Simos about t_player use...
	return (player);
}

void	get_and_check_data(t_vars *game)
{
	game->north = get_texture(game, "NO ");
	game->south = get_texture(game, "SO ");
	game->east = get_texture(game, "EA ");
	game->west = get_texture(game, "WE ");
	game->f_values = get_colour(game, "F ");
	game->c_values = get_colour(game, "C ");
	make_modify_and_check_map(game);
	game->pl = init_player(game);
	find_player_position(game);
	free_array(game->file);
	game->file = NULL;
}
