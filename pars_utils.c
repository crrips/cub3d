/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:22:48 by user              #+#    #+#             */
/*   Updated: 2023/10/26 13:23:39 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_format(char *to_check, char f1, char f2, char f3)
{
	int	last;

	last = ft_strlen(to_check) - 1;
	if (last > 3 && to_check[last] == f3)
	{
		last--;
		if (to_check[last] == f2)
		{
			last--;
			if (to_check[last] == f1)
			{
				last--;
				if (to_check[last] == '.')
					return ;
			}
		}
	}
	exit(ft_perror("invalid format\n"));
}
