/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 12:19:19 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/20 10:44:16 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	count_map_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
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

static bool	is_it_a_map_character(char character)
{
	if (character == '1')
		return (true);
	else if (character == '0')
		return (true);
	else if (character == 'N')
		return (true);
	else if (character == 'S')
		return (true);
	else if (character == 'E')
		return (true);
	else if (character == 'W')
		return (true);
	else
	{
		return (false);
	}
}

bool	check_if_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_it_a_map_character(line[i]) == true)
		{
			return (true);
		}
		i++;
	}
	return (false);
}
