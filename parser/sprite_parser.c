/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:19:26 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/15 12:19:27 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_spr	*create_sprite(int x, int y)
{
	t_spr	*cur_spr;

	cur_spr = (t_spr *)ft_calloc(1, sizeof(t_spr));
	cur_spr->x_pos = x * PXL_SIZE + PXL_SIZE / 2;
	cur_spr->y_pos = y * PXL_SIZE + PXL_SIZE / 2;
	// arr_spr[count] = cur_spr;
	return (cur_spr);
}

void	find_sprites(t_map *s_map)
{
	int		x;
	int		y;
	int		count;
	char	let;
	t_spr	**arr_spr;
	char	**new_arr;

	y = 0;
	count = 0;
	arr_spr = (t_spr **)ft_calloc(s_map->count_spr, sizeof(t_spr *));
	new_arr = s_map->map;
	while (y < s_map->map_height)
	{
		x = 0;
		while (new_arr[y][x])
		{
			let = new_arr[y][x];
			if (let == '2')
			{
				arr_spr[count] = create_sprite(x, y);
				count++;
			}
			x++;
		}
		y++;
	}
	s_map->s_spr = arr_spr;
}
