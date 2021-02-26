/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 01:15:57 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/11 01:15:58 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_border(t_map *s_map, int *y, int *x)
{
	long int	width;
	long int	heigth;

	heigth = s_map->map_height;
	if (*y >= heigth)
		*y = heigth - 1;
	else if (*y < 0)
		*y = 0;
	width = ft_strlen(s_map->map[*y]);
	if (*x >= width)
		*x = width - 1;
	else if (*x < 0)
		*x = 0;
}
