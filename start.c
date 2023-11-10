/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:24:55 by user              #+#    #+#             */
/*   Updated: 2023/11/10 19:57:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start(t_game **game)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window
		(mlx.mlx_ptr, 1080, 800, "CUB3D");
	(*game)->mlx = mlx;
	mlx_key_hook(mlx.win_ptr, key_management, game);
	mlx_hook(mlx.win_ptr, 17, 1L << 2, kill_process, NULL);
	mlx_loop(mlx.mlx_ptr);
}
