/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:43:29 by user              #+#    #+#             */
/*   Updated: 2023/11/05 21:03:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_wall_last(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	while (line[i] == '\n' || line[i] == ' '
		|| line[i] == '\t' || line[i] == '\0')
		i--;
	if (line[i] != '1')
		exit(ft_perror("invalid map\n"));
}

void	check_no_wall(char **map, int pos, void (*operator)(int *i))
{
	int	i;
	int	j;
	
	i = pos;
	j = 0;
	while (map[i][j])
	{
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		while (map[i][j] == '1')
			j++;
		if (map[i][j] == '\n' || map[i][j] == '\0')
			break ;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			operator(&i);
		if (map[i][j] != '1')
			exit(ft_perror("invalid map\n"));
		else
		{
			i = pos;
			j++;
		}
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
		while (line[j] == ' ' || line[j] == '\t')
			j++;
		if (line[j] == 'N' || line[j] == 'S' 
			|| line[j] == 'E' || line[j] == 'W')
			c++;
		if (line[j] == '1')
		{
			(*game)->map.map[i++] = line;
			check_wall_last(line);
		}
		else if (i || line[j] == '0' || c > 4)
			exit(ft_perror("invalid map\n"));
	}
	(*game)->map.map[i] = NULL;
	free(line);
	close(fd);
	check_no_wall((*game)->map.map, 0, increment);
	check_no_wall((*game)->map.map, (*game)->map.size - 1, decrement);
}
