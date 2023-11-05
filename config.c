/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:42:24 by user              #+#    #+#             */
/*   Updated: 2023/11/05 15:54:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_number(int numb)
{
	if (numb >= 0 && numb <= 255)
		return (1);
	exit(ft_perror("invalid color\n"));
}

void	check_all_numbers(t_color f, t_color c)
{
	check_number(f.r);
	check_number(f.g);
	check_number(f.b);
	check_number(c.r);
	check_number(c.g);
	check_number(c.b);
}

void	create_config(char *filename, t_game **game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
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
		(*game)->map.size = set_mapsize(*game, line);
		free(line);
	}
	if (!check_exist(*game))
		exit(ft_perror("invalid config\n"));
	check_all_numbers((*game)->floor, (*game)->ceiling);
	free(line);
	close(fd);
}
