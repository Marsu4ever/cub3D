/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:38:47 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 11:06:32 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	skip_map_section(t_vars *game, int start)
{
	int	end;

	end = get_index_end_of_map(game, start);
	end++;
	return (end);
}

static void	check_for_invalid_characters_in_file(t_vars *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (check_if_indicator(game->file[i]) == true)
		{
			i++;
		}
		else if (check_if_map(game->file[i]) == true)
		{
			i = skip_map_section(game, i);
		}
		else if (game->file[i][0] == '\n')
		{
			i++;
		}
		else
		{
			error_msg_and_exit(INVALID_CHAR_IN_FILE, NULL, game);
		}
	}
}

static void	check_if_map_exists_and_is_last(t_vars *game)
{
	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->file[i])
	{
		if (check_if_identifier(game->file[i]) == true)
			identifier_count++;
		else if (check_if_map(game->file[i]) == true)
		{
			if (identifier_count == 6)
			{
				return ;
			}
			if (identifier_count < 6)
			{
				error_msg_and_exit(MAP_WRONG_PLACE, NULL, NULL);
			}
		}
		i++;
	}
	error_msg_and_exit(MAP_NOT_FOUND, NULL, NULL);
}

static void	check_for_identifier(t_vars *game, char *identifier)
{
	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->file[i])
	{
		if (ft_strncmp(game->file[i], identifier, ft_strlen(identifier)) == 0)
		{
			identifier_count++;
		}
		i++;
	}
	if (identifier_count == 0)
	{
		error_msg_and_exit(NO_IDENTIFIER, identifier, NULL);
	}
	if (identifier_count == 1)
	{
		return ;
	}
	if (identifier_count >= 2)
	{
		error_msg_and_exit(DUPLICATE_IDENTIFIER, identifier, NULL);
	}
}

void	check_file(t_vars *game)
{
	check_for_identifier(game, "NO ");
	check_for_identifier(game, "SO ");
	check_for_identifier(game, "WE ");
	check_for_identifier(game, "EA ");
	check_for_identifier(game, "F ");
	check_for_identifier(game, "C ");
	check_if_map_exists_and_is_last(game);
	check_for_invalid_characters_in_file(game);
}
