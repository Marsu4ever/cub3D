/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:38:47 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/14 10:06:06 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	check_if_map_exists_and_is_last(t_vars *game)
{

	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->config_file[i])
	{
		if (check_if_identifier(game->config_file[i]) == true)
			identifier_count++;
		else if (check_if_map(game->config_file[i]) == true)
		{
			if (identifier_count == 6)
			{
				return ;
			}
			if (identifier_count < 6)
			{
				error_msg_and_exit("Map occurs before identifier in config file.", NULL, NULL);
			}
		}
		i++;
	}
	error_msg_and_exit("No map was found in config file.", NULL, NULL);
}

void	check_for_identifier(t_vars *game, char *identifier)
{
	int	i;
	int	identifier_count;

	i = 0;
	identifier_count = 0;
	while (game->config_file[i])
	{
		if (ft_strncmp(game->config_file[i], identifier, ft_strlen(identifier)) == 0)
		{
			identifier_count++;
		}
		i++;
	}
	// printf("identifier_count: %d\n", identifier_count);
	if (identifier_count == 0)
	{
		error_msg_and_exit("Identifier missing (or needs a separating space)", identifier, NULL);
	}
	if (identifier_count == 1)
	{
		return ;
	}
	if (identifier_count >= 2)
	{
		error_msg_and_exit("Duplicates of identifier detected", identifier, NULL);
	}
}

void	check_config_file(t_vars *game)
{
	check_for_identifier(game, "NO ");
	check_for_identifier(game, "SO ");
	check_for_identifier(game, "WE ");
	check_for_identifier(game, "EA ");
	check_for_identifier(game, "F ");
	check_for_identifier(game, "C ");
	check_if_map_exists_and_is_last(game); 
	/*
		Check config file...
	*/
	/*
		-check for invalid input
			-
	*/
}
