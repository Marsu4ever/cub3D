/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/01 10:23:51 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <math.h> //for all the math functions we will need in raycasting
# include <fcntl.h> //open
# include <unistd.h> //write, read, close
# include <stdio.h> //perror, printf
# include <stdlib.h> //exit, free, malloc
# include <string.h> //strerror
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_game
{
    mlx_t   		*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*north;
	mlx_texture_t	*east;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	char			**map;
	/*c_values*/
	/*f_values*/
}   t_game;

void 	calc_and_make_map(t_game *game, char **av);
void    mlx_functions(t_game *game);

//errors.c
void msg_and_exit(char *msg);


#endif