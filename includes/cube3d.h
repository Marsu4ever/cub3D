/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/03 00:30:10 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define SCREEN_HEIGHT 540
# define SCREEN_WIDTH 960
# define TEXTURE_H 1
# define TEXTURE_W 1
# define FOV 0.55 //field of view

# include <math.h> //math functions for raycasting
# include <fcntl.h> //open
# include <unistd.h> //write, read, close
# include <stdio.h> //perror, printf
# include <stdlib.h> //exit, free, malloc
# include <string.h> //strerror
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_player
{
    double          x_pos;
	double          y_pos;
	double          xdir;
	double          ydir;
	double          x_plane;
	double          y_plane;
	double          x_side_dist;
	double          y_side_dist;
	double          x_delta_dist;
	double          y_delta_dist;
	double          perp_wall_dist;
	int		        x_step;
	int		        y_step;
	int		        hit;
	int		        side;
	int		        line_height;
	double          x_ray_dir;
	double          y_ray_dir;
	double          x_camera;
	double          move_speed;
	double          rot_speed;
	int		        draw_start;
	int		        draw_end;
	int		        x_text;
	int		        y_text;
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
    mlx_texture_t   *east;
    mlx_texture_t   *north;
    mlx_texture_t   *south;
    mlx_texture_t   *west;
    mlx_texture_t   *c_texture;
    mlx_texture_t   *f_texture;
    mlx_texture_t   *text;
    int             c_values;
    int             f_values;
    uint32_t        wall_color;
    double          x_wall;
    int             players_nbr;
}               t_vars;


//calc_and_make_map.c
void 	calc_and_make_map(t_vars *game, char **av);

//mlx_functions.c
void    mlx_functions(t_vars *game);

//render.c
void	render(t_vars *game);
int     get_rgba(int r, int g, int b);
void    create_floor_ceiling(t_vars *game);

//raycasting.c
void    raycasting(t_player *player, t_vars *game);
void    calc_the_rays(t_player *player, int r);
void    hit_check(t_player *player, t_vars *vars);

//errors.c
void    msg_and_exit(char *msg, int fd);


#endif