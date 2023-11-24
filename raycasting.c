/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 23:39:27 by user              #+#    #+#             */
/*   Updated: 2023/11/24 04:15:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pre_draw_textures(t_game *game);
void	draw_textures(t_game *game, int x);

void	find_dist(t_game *game, int x)
{
	double	cam_x;

	cam_x = 2 * x / (double)W - 1;
	game->x_dir_ray = game->x_dir + game->x_plane * cam_x;
	game->y_dir_ray = game->y_dir + game->y_plane * cam_x;
	game->x_map = (int)game->x_pos;
	game->y_map = (int)game->y_pos;
	if (game->x_dir_ray == 0)
		game->delta_dist_x = 1e30;
	else
		game->delta_dist_x = fabs(1 / game->x_dir_ray);
	if (game->y_dir_ray == 0)
		game->delta_dist_y = 1e30;
	else
		game->delta_dist_y = fabs(1 / game->y_dir_ray);
}

void	pre_dda(t_game *game)
{
	game->hit = 0;
	if (game->x_dir_ray < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->x_pos - game->x_map) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->x_map + 1.0 - game->x_pos)
			* game->delta_dist_x;
	}
	if (game->y_dir_ray < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->y_pos - game->y_map) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->y_map + 1.0 - game->y_pos)
			* game->delta_dist_y;
	}
}

void	dda(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->x_map += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->y_map += game->step_y;
			game->side = 1;
		}
		if (game->map.map[game->y_map][game->x_map] == '1')
			game->hit = 1;
	}
}

void	count_frame(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
	game->line_height = (int)(H / game->perp_wall_dist);
	game->draw_start = -game->line_height / 2 + H / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + H / 2;
	if (game->draw_end >= H)
		game->draw_end = H;
}

void	raycating(t_game *game)
{
	int	x;

	x = -1;
	while (++x < W)
	{
		find_dist(game, x);
		pre_dda(game);
		dda(game);
		count_frame(game);
		pre_draw_textures(game);
		draw_textures(game, x);
	}
}
