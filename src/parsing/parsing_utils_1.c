/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:43:18 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 12:20:36 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

char	*character_replace(char	*line, char char_initial, char char_final)
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
	int		value_start;

	value_start = ft_strlen(identifier_key);
	if (line[value_start] == ' ')
	{
		value_start++;
	}
	return (value_start);
}

char	*parse_out_key_and_spaces(char *line, int value_start)
{
	char	*value;

	value = ft_strdup(&line[value_start]);
	if (value == NULL)
	{
		error_msg_and_exit(MALLOC_FAIL, "parse_out_key_and_spaces", NULL);
	}
	return (value);
}

int	get_element_index(t_vars *game, char *identifier)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (ft_strncmp(game->file[i], identifier, ft_strlen(identifier)) == 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

bool	check_if_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
		{
			return (true);
		}
		i++;
	}
	return (false);
}
