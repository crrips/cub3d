/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:25:18 by user              #+#    #+#             */
/*   Updated: 2023/11/24 04:07:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	orient2(t_game *game);

void	orient(t_game *game)
{
	if (game->player.orientation == 'N')
	{
		game->x_dir = 0;
		game->y_dir = 1;
		game->x_plane = 0.66;
		game->y_plane = 0;
	}
	else if (game->player.orientation == 'S')
	{
		game->x_dir = 0;
		game->y_dir = -1;
		game->x_plane = -0.66;
		game->y_plane = 0;
	}
	orient2(game);
}

void	orient2(t_game *game)
{
	if (game->player.orientation == 'E')
	{
		game->x_dir = 1;
		game->y_dir = 0;
		game->x_plane = 0;
		game->y_plane = -0.66;
	}
	else if (game->player.orientation == 'W')
	{
		game->x_dir = -1;
		game->y_dir = 0;
		game->x_plane = 0;
		game->y_plane = 0.66;
	}
}

void	init_tex(t_game *game)
{
	int	i;

	game->tex[0].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->path_tex.no, &game->size, &game->size);
	game->tex[1].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->path_tex.so, &game->size, &game->size);
	game->tex[2].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->path_tex.ea, &game->size, &game->size);
	game->tex[3].img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->path_tex.we, &game->size, &game->size);
	i = 0;
	while (i < 4)
	{
		game->tex[i].img_addr = mlx_get_data_addr(game->tex[i].img_ptr,
				&game->tex[i].bpp, &game->tex[i].line_len,
				&game->tex[i].endian);
		i++;
	}
}

void	init(t_game *game)
{
	orient(game);
	game->size = 64;
	game->w = 0;
	game->a = 0;
	game->s = 0;
	game->d = 0;
	game->l = 0;
	game->r = 0;
	game->x_pos = game->player.x + 0.5;
	game->y_pos = game->player.y + 0.5;
	game->move_speed = 0.03;
	game->rot_speed = 0.025;
	init_tex(game);
}
