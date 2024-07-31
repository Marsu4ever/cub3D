/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/31 13:58:50 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define SCREEN_HEIGHT 540
# define SCREEN_WIDTH 960
# define TEXTURE_H 64
# define TEXTURE_W 64

# include <math.h> //math functions for raycasting
# include <fcntl.h> //open
# include <unistd.h> //write, read, close
# include <stdio.h> //perror, printf
# include <stdlib.h> //exit, free, malloc
# include <string.h> //strerror
# include <libft/headers/libft.h>
# include <libft/headers/get_next_line.h>
# include <MLX42\include\MLX42\MLX42.h>

typedef struct s_player
{
    double	x_pos;
	double	y_pos;
	double	x_dir;
	double	y_dir;
}               t_player;

typedef struct s_vars
{
    mlx_t           *mlx;
    mlx_image_t     *image;
    t_player        *player;
    int             map_start;
    char            *map_path;
    char            **map;
    int             x_map;
    int             y_map;
    mlx_texture_t   *ea_texture;
    mlx_texture_t   *no_texture;
    mlx_texture_t   *so_texture;
    mlx_texture_t   *we_texture;
    mlx_texture_t   *c_texture;
    mlx_texture_t   *f_texture;
    mlx_texture_t   *text;
    int             c_values;
    int             f_values;
    uint32_t        wall_color;
    double          x_wall;
    int             players_nbr;
}               t_vars;

//errors.c
void msg_and_exit(char *msg);


#endif