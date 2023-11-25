/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:52:57 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:54:12 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "mlx.h"

# define W 1080
# define H 800

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	int		size;
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_exist
{
	int	is_no;
	int	is_so;
	int	is_we;
	int	is_ea;
	int	is_f;
	int	is_c;
}	t_exist;

typedef struct s_player
{
	int		x;
	int		y;
	char	orientation;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	bg;
}	t_mlx;

typedef struct s_game
{
	t_texture	path_tex;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_exist		exist;
	t_player	player;
	t_mlx		mlx;
	t_img		tex[4];
	int			size;
	int			x_map;
	int			y_map;
	int			hit;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			w;
	int			a;
	int			s;
	int			d;
	int			l;
	int			r;
	double		x_pos;
	double		y_pos;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
	double		x_dir_ray;
	double		y_dir_ray;
	double		move_speed;
	double		rot_speed;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
}	t_game;

// PARSING
void	parsing(int argc, char **argv, t_game **game);

// PRINT
int		ft_perror(char *s);
void	print_data(t_game **game);
void	print2d(char **map);

// FILE
char	*get_next_line(int fd);

// GETTERS
char	*get_texture(char *line);
t_color	get_color(char *line);

// SETTERS
void	set_texture(char *line, char *txt, char **to_set, int *to_increment);
void	set_color(char *line, char *txt, t_color *to_set, int *to_increment);
int		set_mapsize(t_game *game, char *line);

// PARS UTILS
void	check_format(char *to_check, char f1, char f2, char f3);
int		check_exist(t_game *game);
void	check_all_numbers(t_color f, t_color c);
int		strlen2d(char **map);
void	while_char(char *line, char skip, int *i);

// CREATE
void	create_map(char *filename, t_game **game);
void	create_config(char *filename, t_game **game, int fd);
void	start(t_game *game);

// MAP UTILS
void	check_no_wall(char **map, int pos,
			void (*operator)(int *i, char op), char op);
void	check_wall_last(char *line);
void	identify_char(char **line, int *i, int *c, t_game **game);
void	after_map(char *line, char **map);
void	check_map(t_game **game);
void	check_inside(t_game **game, char **map, int size);	

// MATH
void	operator(int *i, char op);

// DRAW
int		draw(t_game *game);

// INIT
void	init(t_game *game);

// RAYCASTING
void	raycating(t_game *game);

#endif