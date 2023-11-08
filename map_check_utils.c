/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:58 by user              #+#    #+#             */
/*   Updated: 2023/11/08 11:07:09 by user             ###   ########.fr       */
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

void	check_no_wall(char **map, int pos,
void (*operator)(int *i, char op), char op)
{
	int	i;
	int	j;

	i = pos;
	j = 0;
	while (map[i][j])
	{
		while (map[i][j] == ' ')
			j++;
		while (map[i][j] == '1')
			j++;
		if (map[i][j] == '\n' || map[i][j] == '\0')
			break ;
		while (map[i][j] == ' ')
			operator(&i, op);
		if (map[i][j] != '1')
			exit(ft_perror("invalid map\n"));
		else
		{
			i = pos;
			j++;
		}
	}
}
