/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:21 by apiloian          #+#    #+#             */
/*   Updated: 2023/10/29 13:30:23 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_symb(char *line, int *i)
{
	while (ft_isdigit(line[*i]))
		(*i)++;
	while (line[*i] == ' ' || line[*i] == '\t')
		(*i)++;
}

void	skip_comma(char *line, int *i)
{
	while (line[*i] != ',')
	{
		(*i)++;
		if (line[*i] == '\n')
			exit(ft_perror("invalid color\n"));
	}
	while (!ft_isdigit(line[*i]))
	{
		(*i)++;
		if (line[*i] != ' ' && line[*i] != '\t' && !ft_isdigit(line[*i]))
			exit(ft_perror("invalid color\n"));
	}
}

char	*get_texture(char *line)
{
	char	*tex;
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	tex = ft_strtrim(line + i, " \n");
	check_format(tex, 'x', 'p', 'm');
	return (tex);
}

t_color	get_color(char *line)
{
	t_color	color;
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_isdigit(line[i]))
		color.r = ft_atoi(line + i);
	else
		exit(ft_perror("invalid color\n"));
	skip_comma(line, &i);
	color.g = ft_atoi(line + i);
	skip_comma(line, &i);
	color.b = ft_atoi(line + i);
	while (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\n' && ft_isascii(line[i]))
		exit(ft_perror("invalid color\n"));
	return (color);
}
