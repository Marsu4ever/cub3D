/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:19:19 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/23 15:52:59 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	count_map_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

bool	check_if_identifier(char *line)
{
	char	*identifiers[7];
	int		i;

	identifiers[0] = "NO ";
	identifiers[1] = "SO ";
	identifiers[2] = "EA ";
	identifiers[3] = "WE ";
	identifiers[4] = "C ";
	identifiers[5] = "F ";
	identifiers[6] = NULL;
	i = 0;
	while (identifiers[i] != NULL)
	{
		if (ft_strncmp(identifiers[i], line, ft_strlen(identifiers[i])) == 0)
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	check_if_indicator(char *line)
{
	if (ft_strncmp(line, "NO ", ft_strlen("NO ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "SO ", ft_strlen("SO ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "WE ", ft_strlen("WE ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "EA ", ft_strlen("EA ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "F ", ft_strlen("F ")) == 0)
	{
		return (true);
	}
	if (ft_strncmp(line, "C ", ft_strlen("C ")) == 0)
	{
		return (true);
	}
	return (false);
}

int	get_index_end_of_map(t_vars *game, int start)
{
	int	end;

	end = start;
	while (game->file[start])
	{
		if (ft_strchr(game->file[start], '1') != NULL)
		{
			end = start;
		}
		start++;
	}
	return (end);
}
