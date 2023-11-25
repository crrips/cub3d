/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inside.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:26:05 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 09:15:02 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_player	set_player(char **map, int size, int i)
{
	t_player	player;
	int			count;
	int			j;

	count = 0;
	while (i < size)
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSEW", map[i][j]))
			{
				player.x = j;
				player.y = i;
				player.orientation = map[i][j];
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		exit(ft_perror("invalid player\n"));
	return (player);
}

void	check_symb(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01NSEW ", map[i][j]))
				if (map[i][j] != '\n')
					exit(ft_perror("invalid map\n"));
			j++;
		}
		i++;
	}
}

void	check_inside(t_game **game, char **map, int size)
{
	(*game)->player = set_player(map, size, 0);
	check_symb(map, 0, 0);
}
