/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_slice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:16:44 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/02 10:16:46 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_ceil_space(t_map *s_map, int slice_x, int cur, int max_val)
{
	while (cur < max_val)
	{
		pxl_put(&(s_map->s_img), slice_x, cur, s_map->s_parser->ceil_c);
		cur++;
	}
}

void	fill_floor_space(t_map *s_map, int slice_x, int cur, int max_val)
{
	while (cur < max_val)
	{
		pxl_put(&(s_map->s_img), slice_x, cur, s_map->s_parser->floor_c);
		cur++;
	}
}

void	texture_slice_second(t_map *s_map, int slice_height, int slice_x,
														double texture_x)
{
	int				i;
	unsigned int	color;
	int				start_point;
	double			texture_y;
	double			step;

	i = 0;
	step = (double)(s_map->cur_text.height) / slice_height;
	start_point = s_map->h / 2 - slice_height / 2;
	if (slice_height > s_map->h)
		start_point = 0;
	texture_y = (start_point - s_map->h / 2 + slice_height / 2) * step;
	fill_ceil_space(s_map, slice_x, i, start_point);
	while (i < slice_height && i < s_map->h)
	{
		color = *((unsigned int*)s_map->cur_text.addr +
			((int)texture_y * s_map->cur_text.width + (int)texture_x));
		pxl_put(&(s_map->s_img), slice_x, start_point, color);
		start_point++;
		texture_y += step;
		i++;
	}
	fill_floor_space(s_map, slice_x, start_point--, s_map->h);
}

void	texture_slice(t_map *s_map, int slice_height, int slice_x,
												double side_dist)
{
	double			texture_x;

	s_map->cur_text = choose_texture(s_map);
	texture_x = (int)(((side_dist - (int)(side_dist / PXL_SIZE) * PXL_SIZE) /
										PXL_SIZE) * s_map->cur_text.width);
	texture_slice_second(s_map, slice_height, slice_x, texture_x);
}
