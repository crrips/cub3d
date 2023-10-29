/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:43:40 by apiloian          #+#    #+#             */
/*   Updated: 2023/10/29 14:16:35 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(char *line, char *txt, char **to_set, int *to_increment)
{
	if (line[0] == txt[0] && line[1] == txt[1]
		&& (line[2] == ' ' || line[2] == '\t'))
	{
		*to_set = get_texture(line + 2);
		(*to_increment)++;
	}
}

void	set_color(char *line, char *txt, t_color *to_set, int *to_increment)
{
	if (line[0] == txt[0]
		&& (line[1] == ' ' || line[1] == '\t'))
	{
		*to_set = get_color(line + 1);
		(*to_increment)++;
	}
}

void	set_map(t_game *game, char *line)
{
	static int	len = 0;
	
	(void)line;
	if (check_exist(game) && line[0] != '\n')
		len++;
	printf("%d\n", len);
}
