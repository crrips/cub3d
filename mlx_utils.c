/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:34:58 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:57:09 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	kill_process(void)
{
	exit(0);
	return (0);
}

int	press(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		exit(0);
	}
	if (keycode == 13)
		game->w = 1;
	if (keycode == 0)
		game->a = 1;
	if (keycode == 1)
		game->s = 1;
	if (keycode == 2)
		game->d = 1;
	if (keycode == 123)
		game->l = 1;
	if (keycode == 124)
		game->r = 1;
	return (0);
}

int	release(int keycode, t_game *game)
{
	if (keycode == 13)
		game->w = 0;
	if (keycode == 0)
		game->a = 0;
	if (keycode == 1)
		game->s = 0;
	if (keycode == 2)
		game->d = 0;
	if (keycode == 123)
		game->l = 0;
	if (keycode == 124)
		game->r = 0;
	return (0);
}
