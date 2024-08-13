/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:23:25 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/13 12:25:14 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	check_argument_count(int ac)
{
	if (ac != 2)
	{		
		error_msg_and_exit("Pass in just ONE argument.", NULL, NULL);
	}
	return ;
}

static void	check_file_extension(char *av)
{
	/*
		Edge cases
			map_name.cub
			./map_name.cub
			map.cub.cub 

		is it a directory???
	*/

	size_t	i;

	i = ft_strlen(av);
	if (i < 5)
	{
		error_msg_and_exit("File name is too short.", NULL, NULL);
	}
	if (ft_strcmp(av + i - 4, ".cub") != 0)
	{
		error_msg_and_exit("File should end with .cub", NULL, NULL);
	}
}

void	check_user_input(int ac, char *av)
{
    check_argument_count(ac);
	/*
		-check_if_directory
	*/
	check_file_extension(av);
}
