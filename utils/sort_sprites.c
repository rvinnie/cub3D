/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 11:54:13 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/16 11:54:14 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_spr_dists(t_map *s_map, t_spr **s_sprites, int size)
{
	t_spr	*cur_spr;
	int		i;

	i = 0;
	while (size--)
	{
		cur_spr = s_sprites[i];
		cur_spr->dist = hypot(s_map->s_player.x_pos - cur_spr->x_pos,
							s_map->s_player.y_pos - cur_spr->y_pos);
		i++;
	}
}

void	sort_sprites(t_map *s_map, int size)
{
	int		i;
	int		j;
	t_spr	*tmp;
	t_spr	**s_sprites;

	s_sprites = s_map->s_spr;
	update_spr_dists(s_map, s_sprites, size);
	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j > i)
		{
			if ((int)s_sprites[j - 1]->dist < (int)s_sprites[j]->dist)
			{
				tmp = s_sprites[j];
				s_sprites[j] = s_sprites[j - 1];
				s_sprites[j - 1] = tmp;
			}
			j--;
		}
		i++;
	}
}
