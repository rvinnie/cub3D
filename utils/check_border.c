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

#include "../cub3d.h"

int		is_line_nbr(char *line)
{
	int		i;
	char	let;

	i = 0;
	while (line[i])
	{
		let = line[i];
		if (let < '0' || let > '9')
			return (0);
		i++;
	}
	return (1);
}

int		arr_len(char **info_arr)
{
	int count;

	count = 0;
	while (info_arr[count])
		count++;
	return (count);
}

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
