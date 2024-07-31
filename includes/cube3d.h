/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/07/31 14:49:16 by mkorpela         ###   ########.fr       */
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


/* typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	move_speed;
	double	rot_speed;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
}				t_player;

typedef struct s_params
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		*player;
	int				player_amount;
	int				map_start;
	char			*map_path;
	char			**map;
	int				map_x;
	int				map_y;
	mlx_texture_t	*no_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*c_texture;
	mlx_texture_t	*f_texture;
	mlx_texture_t	*text_to_draw;
	int				f_values;
	int				c_values;
	uint32_t		wall_c;
	double			wall_x;
}					t_params; */


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


//errors.c
void msg_and_exit(char *msg);


#endif