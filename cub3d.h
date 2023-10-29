/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:52:57 by apiloian          #+#    #+#             */
/*   Updated: 2023/10/26 14:01:41 by user             ###   ########.fr       */
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
	char	**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_game
{
	t_texture		tex;
	t_color			floor;
	t_color			ceiling;
	t_map			map;
}	t_game;

// PARSING
void	parsing(int argc, char **argv, t_game **game);

// PRINT
int		ft_perror(char *s);
void	print_data(t_game **game);

// FILE
char	*get_next_line(int fd);

// GETTERS
char	*get_texture(char *line);
t_color	get_color(char *line);

// PARS UTILS
void	check_format(char *to_check, char f1, char f2, char f3);

#endif