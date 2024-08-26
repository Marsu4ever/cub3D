/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_user_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:23:25 by mkorpela          #+#    #+#             */
/*   Updated: 2024/08/22 11:12:20 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	check_argument_count(int ac)
{
	if (ac != 2)
	{		
		error_msg_and_exit(WRONG_ARG_COUNT, NULL, NULL);
	}
	return ;
}

static void	check_file_extension(char *av)
{
	size_t	i;

	i = ft_strlen(av);
	if (i < 5)
	{
		error_msg_and_exit(FILE_TOO_SHORT, NULL, NULL);
	}
	if (ft_strcmp(&av[i - 4], ".cub") != 0)
	{
		error_msg_and_exit(FILE_NO_END_CUB, NULL, NULL);
	}
	if (ft_strcmp(&av[i - 5], "/.cub") == 0)
	{
		error_msg_and_exit(HIDDEN_FILE_CUB, NULL, NULL);
	}
}

void	check_user_input(int ac, char *av)
{
	check_argument_count(ac);
	check_file_extension(av);
}
