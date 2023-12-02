/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:43:40 by apiloian          #+#    #+#             */
/*   Updated: 2023/12/02 18:45:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(char *line, char *txt, char **to_set, int *to_increment)
{
	if (line[0] == txt[0])
		(*to_increment)++;
	if (line[0] == txt[0] && line[1] == txt[1]
		&& (line[2] == ' ' || line[2] == '\t'))
	{
		*to_set = get_texture(line + 2);
	}
}

void	set_color(char *line, char *txt, t_color *to_set, int *to_increment)
{
	if (line[0] == txt[0])
		(*to_increment)++;
	if (line[0] == txt[0]
		&& (line[1] == ' ' || line[1] == '\t'))
	{
		*to_set = get_color(line + 1);
	}
}

int	set_mapsize(t_game *game, char *line)
{
	static int	len = 0;
	int			j;

	j = 0;
	while (line[j] == ' ' || line[j] == '\t')
			j++;
	if (check_exist(game) && (line[j] == '1'))
		len++;
	return (len);
}
