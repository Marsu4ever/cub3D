/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:43:18 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/13 15:12:37 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	count_map_rows(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

char	*character_replace(char	*line, char	char_initial, char char_final)
{
	int	i;

	if (char_initial == '\0')
	{
		return (line);
	}
	i = 0;	
	while (line[i] != '\0')
	{
		if (line[i] == char_initial)
		{
			line[i] = char_final;
		}
		i++;
	}
	return (line);
}

int	get_identifier_start(char *line, char *identifier_key)
{
	// char	*value;
	int		value_start;

	value_start = ft_strlen(identifier_key);
	if (line[value_start] == ' ')
	{
		value_start++;
	}
	return (value_start);
/* 	value = ft_strdup(&line[value_start]);
	if (value == NULL)
	{
		error_msg_and_exit("Malloc fail", identifier_key);
	}
	return (value); */
}

char	*parse_out_key_and_spaces(char *line, int value_start)
{
	char	*value;

	value = ft_strdup(&line[value_start]);
	if (value == NULL)
	{
		error_msg_and_exit("Malloc failed", "parse_out_key_and_spaces", NULL);
	}
	return (value);
	// modified_line = character_replace(modified_line, '\n', '\0');
	// return (modified_line);
}

bool	check_if_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])//Consider what spaces are...
	{
		if (line[i] == '1')
		{
			return (true);
		}
		i++;
	}
	return (false);
	// if (line[i] == '1' || line[i] == '0')
	// {
	// 	return (true);
	// }
	// if (line[i] == 'N' || line[i] == 'S')
	// {
	// 	return (true);
	// }
	// if (line[i] == 'W' || line[i] == 'E')
	// {
	// 	return (true);
	// }	
	// else
	// {
		
	// }
}

bool	check_if_identifier(char *line)
{
	char *identifiers[7] = {
		"NO ",
		"SO ",
		"EA ",
		"WE ",
		"C ",
		"F ",
		NULL
    };

	int	i;

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

int	get_element_index(t_vars *game, char *identifier)
{
	int	i;

	i = 0;
	while (game->config_file[i])
	{
		if (ft_strncmp(game->config_file[i], identifier, ft_strlen(identifier)) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
