/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:02 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 08:54:12 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_perror(char *s)
{
	if (!s)
		return (1);
	write(2, "Error\n", 6);
	while (*s != '\0')
	{
		write(2, s, 1);
		s++;
	}
	return (1);
}

void	print2d(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

void	print_data(t_game **game)
{
	printf("north texture\n");
	printf("%s\n", (*game)->path_tex.no);
	printf("south texture\n");
	printf("%s\n", (*game)->path_tex.so);
	printf("west texture\n");
	printf("%s\n", (*game)->path_tex.we);
	printf("east texture\n");
	printf("%s\n", (*game)->path_tex.ea);
	printf("floor color\n");
	printf("%d %d %d\n", (*game)->floor.r, (*game)->floor.g, (*game)->floor.b);
	printf("ceiling color\n");
	printf("%d %d %d\n", (*game)->ceiling.r, (*game)->ceiling.g,
		(*game)->ceiling.b);
	printf("map %d\n", (*game)->map.size);
	printf("player %d %d %c\n", (*game)->player.y, (*game)->player.x,
		(*game)->player.orientation);
	print2d((*game)->map.map);
}
