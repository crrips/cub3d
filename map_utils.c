/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:58 by user              #+#    #+#             */
/*   Updated: 2023/11/08 11:17:49 by user             ###   ########.fr       */
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
		|| line[i] == '\0')
		i--;
	if (line[i] != '1')
		exit(ft_perror("invalid map\n"));
}

void	identify_char(char **line, int *i, int *c, t_game **game)
{
	int	j;

	j = 0;
	while ((*line)[j] == ' ')
			j++;
	if ((*line)[j] == 'N' || (*line)[j] == 'S'
			|| (*line)[j] == 'E' || (*line)[j] == 'W'
			|| (*line)[j] == 'F' || (*line)[j] == 'C')
	{
		(*c)++;
		free(*line);
	}
	else if ((*line)[j] == '\n')
		free(*line);
	else if ((*line)[j] == '1')
	{
		(*game)->map.map[(*i)++] = *line;
		check_wall_last(*line);
	}
	else if (*i || (*line)[j] == '0' || *c > 6)
		exit(ft_perror("invalid map\n"));
}

void	after_map(char *line, char **map)
{
	static char	*save_line;

	if (*map && **map)
	{
		while (*line == ' ')
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
