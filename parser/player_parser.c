/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:47:26 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/02 16:47:27 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	create_player(t_map *s_map, int x, int y, char dir)
{
	s_map->s_player.x_pos = x * PXL_SIZE;
	s_map->s_player.y_pos = y * PXL_SIZE;
	s_map->s_player.direction = dir;
}

void	find_player(t_map *s_map)
{
	int		i;
	int		j;
	int		is_correct;
	char	let;

	i = 0;
	is_correct = 0;
	while (i < s_map->map_height)
	{
		j = 0;
		while (s_map->map[i][j])
		{
			let = s_map->map[i][j];
			// printf("%c\n",let);
			if (find_chr(let, "NSWE"))
			{
				is_correct = 1;
				create_player(s_map, j, i, let);
				break;
			}
			j++;
		}
		i++;
	}
	if (!is_correct)
		put_error(s_map, NULL, 5);
}
