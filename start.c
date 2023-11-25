/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:24:55 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:57:35 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	kill_process(void);
int	press(int keycode, t_game *game);
int	release(int keycode, t_game *game);

void	start(t_game *game)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, W, H, "CUB3D");
	game->mlx = mlx;
	init(game);
	mlx_loop_hook(mlx.mlx_ptr, &draw, game);
	mlx_hook(mlx.win_ptr, 17, 1L << 2, kill_process, NULL);
	mlx_hook(mlx.win_ptr, 2, 1L << 3, press, game);
	mlx_hook(mlx.win_ptr, 3, 1L << 3, release, game);
	mlx_loop(mlx.mlx_ptr);
}
