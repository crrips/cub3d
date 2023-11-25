/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiloian <apiloian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:58 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/25 12:44:57 by apiloian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	operator(int *i, char op)
{
	if (op == '+')
		(*i)++;
	else if (op == '-')
		(*i)--;
}

void	check_obrez(char *line, char *pre, char *after)
{
	size_t	i;
	size_t	prelen;
	size_t	aftlen;

	i = 0;
	if (!line || !pre || !after)
		return ;
	prelen = ft_strlen(pre) - 1;
	aftlen = ft_strlen(after) - 1;
	while (line[i] != '\n')
	{
		if (line[i] == ' ')
		{
			i++;
			continue ;
		}
		if (line[i] != '1' && (prelen < i || aftlen < i
				|| pre[i] == ' ' || after[i] == ' '))
			exit(ft_perror("invalid map\n"));
		i++;
	}
}

void	check_down(char **map, int i, int j)
{
	int	size;

	size = strlen2d(map);
	while (map[i] && map[i][j] != ' ')
		i++;
	while (map[i] && map[i][j] == ' ')
		i++;
	if (map[i] && map[i][j] != '1')
		exit(ft_perror("invalid map\n"));
	i = 1;
	while (i < size)
	{
		check_obrez(map[i], map[i - 1], map[i + 1]);
		i++;
	}
}

void	check_up(char **map, int i, int start_j, size_t start_len)
{
	size_t	len;
	int		j;

	while (map[i][start_j])
		start_j++;
	while (i > -1)
	{
		j = start_j;
		len = ft_strlen(map[i]);
		if (i > 0 && i < (int)strlen2d(map) - 1)
			check_obrez(map[i], map[i - 1], map[i + 1]);
		if (len > start_len)
		{
			while (map[i][j + 1] != '\n')
			{
				if (map[i][j] != '1')
					exit(ft_perror("invalid map\n"));
				j++;
				if (map[i][j + 1] == '\n')
					return ;
			}
		}
		i--;
	}
}

void	check_no_wall(char **map, int pos,
void (*operator)(int *i, char op), char op)
{
	int	i;
	int	j;

	i = pos;
	j = 0;
	while (map[i][j])
	{
		if (op == '+')
			check_down(map, i, j);
		while_char(map[i], ' ', &j);
		while_char(map[i], '1', &j);
		if (op == '-')
			check_up(map, i, j, ft_strlen(map[i]) + 1);
		if (map[i][j] == '\n' || map[i][j] == '\0')
			break ;
		while (map[i][j] == ' ')
			operator(&i, op);
		if (map[i][j] != '1' && map[i][j] != '\n')
			exit(ft_perror("invalid map\n"));
		else
		{
			i = pos;
			j++;
		}
	}
}
