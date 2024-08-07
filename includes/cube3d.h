/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/02 15:19:14 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define SCREEN_HEIGHT 540
# define SCREEN_WIDTH 960
# define TEXTURE_H 1
# define TEXTURE_W 1

# include <math.h> //math functions for raycasting
# include <fcntl.h> //open
# include <unistd.h> //write, read, close
# include <stdio.h> //perror, printf
# include <stdlib.h> //exit, free, malloc
# include <string.h> //strerror
# include "errno.h"
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

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
 
    char            player_start_direction; //N, S, W, E
    int 			player_start_x; // 3
	int 			player_start_y; // 4

    int             map_start;
    char            *map_path;
    char            **map;
    int             x_map;
    int             y_map;
    mlx_texture_t   *east;
    mlx_texture_t   *north;
    mlx_texture_t   *south;
    mlx_texture_t   *west;
    mlx_texture_t   *text;
    int             c_values;
    int             f_values;
    uint32_t        wall_color;
    double          x_wall;
    int             players_nbr;


/* Quick fix variables*/
    char            **whole_file; 
}               t_vars;


//calc_and_make_map.c
void 	calc_and_make_map(t_vars *game, char **av);

//errors.c
void msg_and_exit(char *msg, int fd);

//mlx_functions.c
void    mlx_functions(t_vars *game);

//parsing.c
void	parsing(t_vars *game, int ac, char **av);

//render.c
void	render(t_vars *game);
int     get_rgba(int r, int g, int b);
void    create_floor_ceiling(t_vars *game);


#endif