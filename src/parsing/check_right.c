/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_right.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:49:18 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/15 12:46:47 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_last_char_is_one(t_vars *game, char *line)
{
	int	last_char;

	last_char = ft_strlen(line) - 1;
	if (line[last_char] != '1')
	{
		// printf("line[last_char]: %c\n", line[last_char]);
		// printf("line: %s\n", line);
		error_msg_and_exit(MAP_NOT_CLOSED, "Check last char on right edge", game);
	}
}

void	check_lines_end_with_1(t_vars *game, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		check_last_char_is_one(game, map[i]);
		i++;
	}
}

void	check_overhanging_chars(t_vars *game, char *line, int other_row_len)
{
	int	i;

	i = other_row_len;
	while (line[i])
	{
		if (line[i] != '1')
		{
			// printf("char: %c\n", line[i]);
			// printf("line: %s\n", line);
			error_msg_and_exit(MAP_NOT_CLOSED, "Check right edge", game);
		}
		i++;
	}
}

void	check_overhanging_chars_are_1(t_vars *game, char **map, int row_count)
{
	int	i;
	int	row1;
	int	row2;

	i = 0;
	while (i < row_count - 1)
	{
		row1 = ft_strlen(map[i]);
		row2 = ft_strlen(map[i + 1]);
		if ((row1 == row2) || (row1 == row2 + 1) || (row1 + 1 == row2))
			;
		else
		{
			// printf("map[%d    ]: %s\n", i, map[i]);
			// printf("map[%d + 1]: %s\n", i, map[i + 1]);
			if (row1 < row2)
			{
				check_overhanging_chars(game, map[i + 1], row1);
			}
			if (row1 > row2)
			{
				check_overhanging_chars(game, map[i], row2);
			}
		}
		i++;
	}	
}

void	check_right(t_vars *game, char **map, int row_count)
{
	check_lines_end_with_1(game, map);
	check_overhanging_chars_are_1(game, map, row_count);
}
