/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:06:44 by user              #+#    #+#             */
/*   Updated: 2023/10/26 14:01:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_file(char *map_name, t_game **game)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit(ft_perror("invalid file\n"));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == 'N' && line[1] == 'O'
			&& (line[2] == ' ' || line[2] == '\t'))
			(*game)->tex.no = get_texture(line + 2);
		else if (line[0] == 'S' && line[1] == 'O'
			&& (line[2] == ' ' || line[2] == '\t'))
			(*game)->tex.so = get_texture(line + 2);
		else if (line[0] == 'W' && line[1] == 'E'
			&& (line[2] == ' ' || line[2] == '\t'))
			(*game)->tex.we = get_texture(line + 2);
		else if (line[0] == 'E' && line[1] == 'A'
			&& (line[2] == ' ' || line[2] == '\t'))
			(*game)->tex.ea = get_texture(line + 2);
		else if (line[0] == 'F'
			&& (line[1] == ' ' || line[1] == '\t'))
			(*game)->floor = get_color(line + 1);
		else if (line[0] == 'C'
			&& (line[1] == ' ' || line[1] == '\t'))
			(*game)->ceiling = get_color(line + 1);
		// else if (line[0] != '\n')
		// 	printf("map\n");
		free(line);
	}
	free(line);
	close(fd);
}

void	parsing(int argc, char **argv, t_game **game)
{
	if (argc == 2)
	{
		check_format(argv[1], 'c', 'u', 'b');
		read_file(argv[1], game);
	}
	else
		exit(ft_perror("invalid arguments\n"));
}
