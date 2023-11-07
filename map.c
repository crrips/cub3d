/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:43:29 by user              #+#    #+#             */
/*   Updated: 2023/11/07 14:58:27 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	after_map(char *line, char **map)
{
	static char	*save_line;

	if (*map && **map)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == '\n')
		{
			save_line = ft_strdup(line);
			return ;
		}
		if (*line != '\n' && save_line && *save_line == '\n')
			exit(ft_perror("invalid map\n"));	
	}
}

void	create_map(char *filename, t_game **game)
{
	int		fd;
	char	*line;
	int		i;
	int		j;
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
		j = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		after_map(line, (*game)->map.map);
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] == 'N' || line[j] == 'S' 
			|| line[j] == 'E' || line[j] == 'W'
			|| line[j] == 'F' || line[j] == 'C')
		{
			free(line);
			c++;
		}
		else if (line[j] == '\n')
			free(line);
		else if (line[j] == '1')
		{
			(*game)->map.map[i++] = line;
			check_wall_last(line);
		}
		else if (i || line[j] == '0' || c > 6)
			exit(ft_perror("invalid map\n"));
	}
	(*game)->map.map[i] = NULL;
	close(fd);
	check_no_wall((*game)->map.map, 0, increment);
	check_no_wall((*game)->map.map, (*game)->map.size - 1, decrement);
}
