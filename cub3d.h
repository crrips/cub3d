/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:52:57 by apiloian          #+#    #+#             */
/*   Updated: 2023/10/30 11:48:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"

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

typedef struct s_game
{
	t_texture		tex;
	t_color			floor;
	t_color			ceiling;
	t_map			map;
	t_exist			exist;
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

#endif