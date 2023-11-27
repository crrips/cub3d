/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 04:17:34 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/27 18:41:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *game, double old_x_dir, double old_x_plane)
{
	old_x_dir = game->x_dir;
	old_x_plane = game->x_plane;
	if (game->l && !game->r)
	{
		game->x_dir = game->x_dir * cos(game->rot_speed)
			- game->y_dir * sin(game->rot_speed);
		game->y_dir = old_x_dir * sin(game->rot_speed)
			+ game->y_dir * cos(game->rot_speed);
		game->x_plane = game->x_plane * cos(game->rot_speed)
			- game->y_plane * sin(game->rot_speed);
		game->y_plane = old_x_plane * sin(game->rot_speed)
			+ game->y_plane * cos(game->rot_speed);
	}
	if (game->r && !game->l)
	{
		game->x_dir = game->x_dir * cos(-game->rot_speed)
			- game->y_dir * sin(-game->rot_speed);
		game->y_dir = old_x_dir * sin(-game->rot_speed)
			+ game->y_dir * cos(-game->rot_speed);
		game->x_plane = game->x_plane * cos(-game->rot_speed)
			- game->y_plane * sin(-game->rot_speed);
		game->y_plane = old_x_plane * sin(-game->rot_speed)
			+ game->y_plane * cos(-game->rot_speed);
	}
}

void	move_wa(t_game *game)
{
	if (game->w)
	{
		if (game->map.map[(int)(game->y_pos)]
		[(int)(game->x_pos + game->x_dir * game->move_speed)] != '1')
			game->x_pos += game->x_dir * game->move_speed;
		if (game->map.map[(int)(game->y_pos + game->y_dir * game->move_speed)]
		[(int)(game->x_pos)] != '1')
			game->y_pos += game->y_dir * game->move_speed;
	}
	if (game->a)
	{
		if (game->map.map[(int)(game->y_pos)]
		[(int)(game->x_pos - game->x_plane * game->move_speed)] != '1')
			game->x_pos -= game->x_plane * game->move_speed;
		if (game->map.map[(int)(game->y_pos - game->y_plane * game->move_speed)]
		[(int)(game->x_pos)] != '1')
			game->y_pos -= game->y_plane * game->move_speed;
	}
}

void	move_sd(t_game *game)
{
	if (game->s)
	{
		if (game->map.map[(int)(game->y_pos)]
		[(int)(game->x_pos - game->x_dir * game->move_speed)] != '1')
			game->x_pos -= game->x_dir * game->move_speed;
		if (game->map.map[(int)(game->y_pos - game->y_dir * game->move_speed)]
		[(int)(game->x_pos)] != '1')
			game->y_pos -= game->y_dir * game->move_speed;
	}
	if (game->d)
	{
		if (game->map.map[(int)(game->y_pos)]
		[(int)(game->x_pos + game->x_plane * game->move_speed)] != '1')
			game->x_pos += game->x_plane * game->move_speed;
		if (game->map.map[(int)(game->y_pos + game->y_plane * game->move_speed)]
		[(int)(game->x_pos)] != '1')
			game->y_pos += game->y_plane * game->move_speed;
	}
}

void	moving(t_game *game)
{
	move_wa(game);
	move_sd(game);
	rotate(game, 0, 0);
}
