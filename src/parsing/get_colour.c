/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:25:55 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/23 13:57:23 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	check_if_only_digits_and_commas(t_vars *game, char *value,
			char *identifier)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if ((value[i] >= '0' && value[i] <= '9') || value[i] == ',')
		{
			i++;
		}
		else
		{
			free(value);
			error_msg_and_exit(COLOUR_INVALID_CHAR, identifier, game);
		}
	}
}

static void	increment_index_when_digit(char *value, int *i)
{
	while (value[*i] >= '0' && value[*i] <= '9')
	{
		(*i)++;
	}
}

static void	check_for_3_numbers_and_2_commas(t_vars *game, char	*value,
			char *identifier)
{
	int	number_count;
	int	comma_count;
	int	i;

	number_count = 0;
	comma_count = 0;
	i = 0;
	while (value[i])
	{
		if (value[i] >= '0' && value[i] <= '9')
		{
			increment_index_when_digit(value, &i);
			number_count++;
		}
		if (value[i] >= ',')
		{
			i++;
			comma_count++;
		}
	}
	if (number_count != 3 || comma_count != 2)
	{
		free(value);
		error_msg_and_exit(COLOUR_INVALID_FORMAT, identifier, game);
	}
}

static int	check_range_and_get_colour_value(t_vars *game, char *value,
			char *identifier)
{
	int		rgb_numbers[3];
	char	**rgb_strings;
	int		i;
	int		number;

	rgb_strings = ft_split(value, ',');
	free(value);
	if (rgb_strings == NULL)
	{
		error_msg_and_exit(MALLOC_FAIL, identifier, game);
	}
	i = 0;
	while (i < 3)
	{
		number = ft_atoi(rgb_strings[i]);
		if (number > 255 || number < 0)
		{
			free_array(rgb_strings);
			error_msg_and_exit(COLOUR_WRONG_RANGE, identifier, game);
		}
		rgb_numbers[i] = number;
		i++;
	}
	free_array(rgb_strings);
	return (get_rgba(rgb_numbers[0], rgb_numbers[1], rgb_numbers[2]));
}

int	get_colour(t_vars *game, char *identifier)
{
	char	*value;
	int		value_start;
	int		i;
	int		colour_value;

	i = get_element_index(game, identifier);
	value_start = get_identifier_start(game->file[i], identifier);
	value = parse_out_key_and_spaces(game, game->file[i], value_start);
	value = character_replace(value, '\n', '\0');
	check_if_only_digits_and_commas(game, value, identifier);
	check_for_3_numbers_and_2_commas(game, value, identifier);
	colour_value = -1;
	colour_value = check_range_and_get_colour_value(game, value, identifier);
	return (colour_value);
}
