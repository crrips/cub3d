/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:58 by user              #+#    #+#             */
/*   Updated: 2023/11/05 21:12:38 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	increment(int	*i)
{
	(*i)++;
}

void	decrement(int	*i)
{
	(*i)--;
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
