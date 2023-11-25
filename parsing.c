/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:06:44 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 12:13:26 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**reverse_map(char **map, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = map[i];
		map[i++] = map[j];
		map[j--] = tmp;
	}
	return (map);
}

void	parsing(int argc, char **argv, t_game **game)
{
	if (argc == 2)
	{
		check_format(argv[1], 'c', 'u', 'b');
		create_config(argv[1], game, 0);
		create_map(argv[1], game);
		(*game)->map.map = reverse_map((*game)->map.map, (*game)->map.size);
		check_map(game);
	}
	else
		exit(ft_perror("invalid arguments\n"));
}
