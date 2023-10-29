/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:10:58 by user              #+#    #+#             */
/*   Updated: 2023/10/26 14:02:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_perror(char *s)
{
	if (!s)
		return (1);
	write(2, "Error\n", 6);
	while (*s != '\0')
	{
		write(2, s, 1);
		s++;
	}
	return (1);
}

void	print_data(t_game **game)
{
	printf("north texture\n");
	printf("%s\n", (*game)->tex.no);
	printf("south texture\n");
	printf("%s\n", (*game)->tex.so);
	printf("west texture\n");
	printf("%s\n", (*game)->tex.we);
	printf("east texture\n");
	printf("%s\n", (*game)->tex.ea);
	printf("floor color\n");
	printf("%d %d %d\n", (*game)->floor.r, (*game)->floor.g, (*game)->floor.b);
	printf("ceiling color\n");
	printf("%d %d %d\n", (*game)->ceiling.r, (*game)->ceiling.g, (*game)->ceiling.b);
}
