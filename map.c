/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:43:29 by user              #+#    #+#             */
/*   Updated: 2023/11/08 10:36:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(char *filename, t_game **game)
{
	int		fd;
	char	*line;
	int		i;
	int		c;

	i = 0;
	c = 0;
	if ((*game)->map.size < 3)
		exit(ft_perror("invalid map\n"));
	(*game)->map.map = malloc(((*game)->map.size + 1) * sizeof(char *));
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(ft_perror("invalid file\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		after_map(line, (*game)->map.map);
		identify_char(&line, &i, &c, game);
	}
	(*game)->map.map[i] = NULL;
	close(fd);
}

void	check_map(t_game **game)
{
	check_no_wall((*game)->map.map, 0, operator, '+');
	check_no_wall((*game)->map.map, (*game)->map.size - 1, operator, '-');
}
