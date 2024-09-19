/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorpela <mkorpela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:48:25 by stigkas           #+#    #+#             */
/*   Updated: 2024/09/19 10:39:32 by mkorpela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define SCREEN_H 896
# define SCREEN_W 1280
# define TEXTURE_W 128
# define TEXTURE_H 128
# define FOV 0.66
# define PI 3.14159265358979323846
# define ROT 0.1
# define SPEED 0.3

# include <math.h> //math functions for raycasting
# include <fcntl.h> //open
# include <unistd.h> //write, read, close
# include <stdlib.h> //exit, free, malloc
# include <string.h> //strerror
# include "errno.h" //errno
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

enum				e_codes
{
	WRONG_ARG_COUNT,
	FILE_TOO_SHORT,
	HIDDEN_FILE_CUB,
	FILE_NO_END_CUB,
	OPEN_FUNC_FAIL,
	MALLOC_FAIL,
	NO_IDENTIFIER,
	DUPLICATE_IDENTIFIER,
	TEXTURE_TOO_SHORT,
	TEXTURE_NO_END_PNG,
	HIDDEN_FILE_PNG,
	LOAD_PNG_FAIL,
	COLOUR_INVALID_CHAR,
	COLOUR_INVALID_FORMAT,
	COLOUR_WRONG_RANGE,
	NEWLINE_IN_MAP,
	INVALID_CHAR_IN_MAP,
	MAP_WRONG_PLACE,
	MAP_NOT_FOUND,
	NO_PLAYER_FOUND,
	TOO_MANY_PLAYERS,
	MAP_TOO_FEW_ROWS,
	MAP_NOT_CLOSED,
	INVALID_CHAR_IN_FILE,
	MLX_INIT_FAIL,
	MLX_NEW_IMAGE_FAIL,
	MLX_IMG_TO_WINDOW_FAIL,
	MLX_LOOP_HOOK_FAIL,
}					;

typedef struct s_ray
{
	double			x_rdir;
	double			y_rdir;
	double			xside_d;
	double			yside_d;
	double			perp_wdist;
	double			wall_h;
	int				side;
}			t_ray;

typedef struct s_player
{
	double			x_pos;
	double			y_pos;
	double			xdir;
	double			ydir;
	double			x_plane;
	double			y_plane;
	int				x_step;
	int				y_step;
	int				hit;
	double			x_camera;
	double			move_speed;
	double			rot_speed;
	double			w_start;
	double			w_end;
	int				x_tex;
	int				y_texture;
	t_ray			*ray;
}			t_player;

typedef struct s_vars
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_player		*pl;
	char			player_start_direction;
	int				player_start_x;
	int				player_start_y;
	int				map_start;
	char			*map_path;
	char			**map;
	int				x_map;
	int				y_map;
	mlx_texture_t	*east;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*texture;
	int				c_values;
	int				f_values;
	uint32_t		paint;
	double			hit_pos;
	int				players_nbr;// is this needed?
	char			**file;
}			t_vars;

//buildsomewalls.c
uint32_t		paint_wslice(t_player *player, t_vars *game, int x, uint32_t *pixar);
int				pos_valid(t_vars *game);
void			render_wall_slice(int r, t_player *player, t_vars *game);
mlx_texture_t	*texture_pick(t_vars *game);
int				x_texture(t_vars *game);
void			wall_slicing(t_vars *game);

//check_if_closed.c
void			check_if_closed(t_vars *game, char **map);

//check_file.c
void			check_file(t_vars *game);

//check_right.c
void			check_right(t_vars *game, char **map, int row_count);

//check_user_input.c
void			check_user_input(int ac, char *av);

//compass.c
void			n_s_compass(t_player *player, double num, double nmro);
void			e_w_compass(t_player *player, double num, double nmro);

// error_message_selector.c
void			error_msg_selector(int error);

//errors.c
int				error_msg_and_exit(int error_number, char *specifier, t_vars *game);

//find_player_position.c
void			find_player_position(t_vars *game);

//free_utils.c
void			destroy_textures(t_vars *game);
void			free_all(t_vars *game);
void			free_array(char **array);
void			free_incomplete_array(char **array, int i);

//get_and_check_data.c
void			get_and_check_data(t_vars *game);

//get_colour.c
int				get_colour(t_vars *game, char *identifier);

//make_modify_and_check_map_1.c
void			make_modify_and_check_map(t_vars *game);

//make_modify_and_check_map_2.c
void			modify_map(char **map);
void			new_line_check(t_vars *game, char **map);

//make_modify_and_check_map_3.c
void			check_for_invalid_characters(t_vars *game, char **map);
void			check_number_of_players(t_vars *game, char **map);

//move.c
void			move_w(t_vars *game);
void			move_a(t_vars *game);
void			move_s(t_vars *game);
void			move_d(t_vars *game);
int				hit_a_wall(t_vars *game, double new_x, double new_y);

//move_hook.c
void			move_hook(mlx_key_data_t keydata, void *game_from_key_hook);

//parsing.c
void			parsing(t_vars *game, int ac, char **av);

//parsing_utils.c
char			*character_replace(char	*line, char char_initial, char char_final);
bool			check_if_identifier(char *line);
bool			check_if_indicator(char *line);
bool			check_if_map(char *line);
int				count_map_rows(char **map);
int				get_element_index(t_vars *game, char *identifier);
int				get_identifier_start(char *line, char *identifier_key);
int				get_index_end_of_map(t_vars *game, int start);
char			*parse_out_key_and_spaces(t_vars *game, char *line, int value_start);

//raycasting.c
void			calc_rays(t_vars *game);
void			init_rays(t_player *player, int r);

//read_file.c
void			read_file(t_vars *game, char *av);

//render.c
void			create_the_maze(int x, t_vars *game);
int				give_rgba(int r, int g, int b);

//rotate_and_move_utils.c
void			rotate_left(t_vars *game);
void			rotate_right(t_vars *game);

//run_wolfenstein.c
void			run_wolfenstein(t_vars *game);

#endif