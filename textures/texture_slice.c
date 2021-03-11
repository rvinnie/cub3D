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

#include "../includes/cub3d.h"

t_text	choose_texture(t_map *s_map) // clear
{
	int		count;
	char	alpha_dir_h;
	char	alpha_dir_v;
	char	hit_dir;
	double	alpha;

	alpha = s_map->s_ray->alpha;
	if (s_map->s_ray->hor_dist < s_map->s_ray->ver_dist)
		hit_dir = 'h';
	else
		hit_dir = 'v';

	if (alpha >= 0 && alpha <= M_PI)
		alpha_dir_h = '+';
	else
		alpha_dir_h = '-';

	if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
		alpha_dir_v = '-';
	else
		alpha_dir_v = '+';
	count = 0;
	if (hit_dir == 'h')
	{
		if (alpha_dir_h == '+')
			count = 0;
		else
			count = 1;
	}
	else 
	{
		if (alpha_dir_v == '+')
			count = 2;
		else
			count = 3;
	}
	return (*s_map->s_text[count]);
}

void	fill_space(t_map *s_map, int slice_x, int cur, int max_val, unsigned int color)
{
	while (cur < max_val)
	{
		pxl_put(&(s_map->s_img), slice_x, cur, color, 1);
		cur++;
	}
}

void	texture_slice_second(t_map *s_map, int slice_height, int slice_x, double step, double texture_x)
{
	int				i;
	unsigned int	color;
	int				start_point;
	double			texture_y;

	i = 0;
	start_point = s_map->h / 2 - slice_height / 2;
	if (slice_height > s_map->h)
		start_point = 0;
	texture_y = (start_point - s_map->h / 2 + slice_height / 2) * step;
	fill_space(s_map, slice_x, i, start_point, s_map->s_parser->ceil_c);
	while (i < slice_height && i < s_map->h)
	{
		color = *((unsigned int*)s_map->cur_text.addr + ((int)texture_y * s_map->cur_text.width + (int)texture_x));
		pxl_put(&(s_map->s_img), slice_x, start_point, color, 1);
		start_point++;
		texture_y += step;
		i++;
	}
	fill_space(s_map, slice_x, start_point--, s_map->h, s_map->s_parser->floor_c);
}

void	texture_slice(t_map *s_map, int slice_height, int slice_x, double side_dist)
{
	double			texture_x;
	double			step;

	s_map->cur_text = choose_texture(s_map);
	texture_x = (int)(((side_dist - (int)(side_dist / PXL_SIZE) * PXL_SIZE) / PXL_SIZE) * s_map->cur_text.width);
	step = (double)(s_map->cur_text.height) / slice_height;
	texture_slice_second(s_map, slice_height, slice_x, step, texture_x);
}
