/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:06:44 by user              #+#    #+#             */
/*   Updated: 2023/10/29 14:08:10 by apiloian         ###   ########.fr       */
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
		set_texture(line, "NO", &(*game)->tex.no, &(*game)->exist.is_no);
		set_texture(line, "SO", &(*game)->tex.so, &(*game)->exist.is_so);
		set_texture(line, "WE", &(*game)->tex.we, &(*game)->exist.is_we);
		set_texture(line, "EA", &(*game)->tex.ea, &(*game)->exist.is_ea);
		set_color(line, "F", &(*game)->floor, &(*game)->exist.is_f);
		set_color(line, "C", &(*game)->ceiling, &(*game)->exist.is_c);
		set_map(*game, line);
		free(line);
	}
	if (!check_exist(*game))
		exit(ft_perror("duplicate in config\n"));
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
