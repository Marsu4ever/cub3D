/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/08/13 15:13:01 by mkorpela         ###   ########.fr       */
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
# include "errno.h"	//to set errno if open or other function fails
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
	double          x_side_dist; //represents the distance the ray has done from player's position to the first grid line in the x direction
	double          y_side_dist; //represents the distance the ray has done from player's position to the first grid line in the y direction
	double          x_delta_dist; //represents the distance the ray has to travel along the x-axis to move from one vertical grid line to the next
	double          y_delta_dist; //represents the distance the ray has to travel along the y-axis to move from one horizontal grid line to the next
	double          perp_wall_dist; //perpendtical wall distance
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
    char            **config_file; 
}               t_vars;

//calc_and_make_map.c
void 	calc_and_make_map(t_vars *game, char **av);

//check_config_file.c
void	check_config_file(t_vars *game);

//check_if_closed.c
void	check_if_closed(t_vars *game, char **map);

//check_right.c
void	check_right(t_vars *game, char **map, int row_count);

//check_user_input.c
void	check_user_input(int ac, char *av);

//compass.c
void n_s_compass(t_player * player, double num, double nmro);
void e_w_compass(t_player * player, double num, double nmro);

//errors.c
void	error_msg_and_exit(char	*msg, char *specifier, t_vars *game);
void    msg_and_exit(char *msg, int fd);

//find_player_position.c
void	find_player_position(t_vars *game);
void	orientation_calc(char compass, t_vars *game);

//free_utils.c
void	free_array(char **array);

//get_colour.c
int	get_colour(t_vars *game, char *identifier);

//get_map.c
char	**get_map(t_vars *game);

//mlx_functions.c
void    mlx_functions(t_vars *game);

//parsing.c
int     get_rgba(int r, int g, int b);  //Does this stay here?
void	parsing(t_vars *game, int ac, char **av);

//raycasting.c
void    raycasting(t_player *player, t_vars *game);
void    init_rays(t_player *player, int r);
void    delta_dist(t_player *player, t_vars *vars);

//read_config_file.c
void	read_config_file(t_vars *game, char *av);

//render.c
void	render(t_vars *game);
int     get_rgba(int r, int g, int b);
void    create_floor_ceiling(t_vars *game);

//parsing_utils.c
char	*character_replace(char	*line, char	char_initial, char char_final);
bool	check_if_identifier(char *line);
bool	check_if_indicator(char *line);
bool	check_if_map(char *line);
int		count_map_rows(char **map);
int		get_element_index(t_vars *game, char *identifier);
int		get_identifier_start(char *line, char *identifier_key);
char	*parse_out_key_and_spaces(char *line, int value_start);

#endif