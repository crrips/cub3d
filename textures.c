/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:39:27 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:57:41 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_draw_textures(t_game *game)
{
	double	wall_x;

	if (game->side == 0)
		wall_x = game->y_pos + game->perp_wall_dist * game->y_dir_ray;
	else
		wall_x = game->x_pos + game->perp_wall_dist * game->x_dir_ray;
	wall_x -= floor(wall_x);
	game->tex_x = (int)(wall_x * (double)64);
	if (game->side == 0 && game->x_dir_ray > 0)
		game->tex_x = 64 - game->tex_x - 1;
	if (game->side == 1 && game->y_dir_ray < 0)
		game->tex_x = 64 - game->tex_x - 1;
}

int	set_textures(t_game *game)
{
	if (game->side && game->y_dir_ray > 0)
		return (0);
	else if (game->side && game->y_dir_ray < 0)
		return (1);
	else if (!game->side && game->x_dir_ray > 0)
		return (2);
	else if (!game->side && game->x_dir_ray < 0)
		return (3);
	return (-1);
}

void	my_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->mlx.bg.img_addr + (y * game->mlx.bg.line_len + \
			x * (game->mlx.bg.bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_textures(t_game *game, int x)
{
	char	*dst;
	int		tex_y;
	double	tex_pos;
	int		i;
	double	step;

	step = 1.0 * 64 / game->line_height;
	tex_pos = (game->draw_start - H / 2 + game->line_height / 2) * (step);
	i = set_textures(game);
	while (game->draw_start < game->draw_end)
	{
		tex_y = (int)tex_pos & (64 - 1);
		tex_pos += step;
		dst = game->tex[i].img_addr + (tex_y * \
			game->tex[i].line_len + \
			game->tex_x * \
			(game->tex[i].bpp / 8));
		my_pixel_put(game, x, game->draw_start++, *(unsigned int *)dst);
	}
}
