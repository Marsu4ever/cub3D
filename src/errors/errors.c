/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:36:24 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/14 10:18:33 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	msg_and_exit(char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	exit(1);
}

void	error_msg_and_exit(char	*msg, char *specifier, t_vars *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	if (specifier != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(specifier, 2);
	}
	ft_putstr_fd("\n", 2);
	if (game != NULL)
	{
		/*free and destroy*/
	}
	exit (1);
}
