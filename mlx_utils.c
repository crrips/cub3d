/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:34:58 by user              #+#    #+#             */
/*   Updated: 2023/11/10 19:51:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	kill_process(void)
{
	exit(0);
	return (0);
}

int	key_management(int keycode, t_game **game)
{
	if (keycode == 53)
	{
		mlx_destroy_window((*game)->mlx.mlx_ptr, (*game)->mlx.win_ptr);
		exit(0);
	}
	return (0);
}
