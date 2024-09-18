/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 13:47:37 by mkorpela          #+#    #+#             */
/*   Updated: 2024/09/18 13:15:52 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	parsing(t_vars *game, int ac, char **av)
{
	check_user_input(ac, av[1]);
	read_file(game, av[1]);
	check_file(game);
	get_and_check_data(game);
}
