/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:24:40 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:56:28 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	moving(t_game *game);

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw_color(t_game *game)
{
	unsigned int	*dst;
	unsigned int	i;
	unsigned long	c;
	unsigned long	f;

	dst = (unsigned int *) game->mlx.bg.img_addr;
	c = create_rgb(game->ceiling.r, game->ceiling.g, game->ceiling.b);
	f = create_rgb(game->floor.r, game->floor.g, game->floor.b);
	i = W * H / 2 + 1;
	while (i-- > 0)
		*dst++ = c;
	i = W * H / 2 + 1;
	while (i-- > 0)
		*dst++ = f;
}

int	draw(t_game *game)
{
	game->mlx.bg.img_ptr = mlx_new_image(game->mlx.mlx_ptr, W, H);
	game->mlx.bg.img_addr = mlx_get_data_addr(game->mlx.bg.img_ptr,
			&game->mlx.bg.bpp, &game->mlx.bg.line_len, &game->mlx.bg.endian);
	draw_color(game);
	raycating(game);
	moving(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->mlx.bg.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.bg.img_ptr);
	return (0);
}
