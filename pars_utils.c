/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:30:12 by apiloian          #+#    #+#             */
/*   Updated: 2023/11/05 16:44:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(char *to_check, char f1, char f2, char f3)
{
	int	last;

	last = ft_strlen(to_check) - 1;
	if (last > 3 && (to_check[last - 2] == 'c'
		|| to_check[last -2] == 'x' || to_check[last - 2] == 'X')
		&& ft_tolower(to_check[last]) == f3)
	{
		last--;
		if (ft_tolower(to_check[last]) == f2)
		{
			last--;
			if (ft_tolower(to_check[last]) == f1)
			{
				last--;
				if (ft_tolower(to_check[last]) == '.')
					return ;
			}
		}
	}
	exit(ft_perror("invalid format\n"));
}

int	check_exist(t_game *game)
{
	if (game->exist.is_no != 1 || game->exist.is_so != 1 || game->exist.is_we != 1
		|| game->exist.is_ea != 1 || game->exist.is_f != 1 || game->exist.is_c != 1)
		return (0);
	return (1);
		
}
