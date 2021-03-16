/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hanler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:07:11 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/15 13:07:14 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_min(double a, double b)
{
	if (fabs(a - b) < 0.00001)
		return (a);
	return (b);
}

void	draw_sprite(t_map *s_map, double sprite_size, double sprite_dir, double spr_dist, double *dists)
{
	int i;
	int j;
	double h_offset;
	double v_offset;

	h_offset = (s_map->s_ray->fov_angle - sprite_dir) / (M_PI / 3) * (s_map->w) + (s_map->w / 2) - (sprite_size / 2);
	v_offset = s_map->h / 2 - sprite_size / 2;
	i = 0;
	while (i < sprite_size)
	{
		// if (h_offset + i < 0  || h_offset + i > s_map->w)
		if (h_offset + i > s_map->w)
			break ;
		j = 0;
		while (j < sprite_size)
		{
			if (v_offset + j > s_map->h || v_offset + j < 0)
				break ;
			if (dists[(int)(h_offset + i)] >= spr_dist)
				pxl_put(&(s_map->s_img), h_offset + i, v_offset+j, 0x00000000, 1);
			j++;
		}
		i++;
	}
}

void    sprite_handler(t_map *s_map, double *dists)
{
	t_spr			*current_spr;
	int				i;
	double			x_spr;
	double			y_spr;
	double			sprite_size;
	double			sprite_dir;
	double			diff;

	i = 0;
	while (i < s_map->count_spr)
	{
		current_spr = s_map->s_spr[i++];
		x_spr = current_spr->x_pos;
		y_spr = current_spr->y_pos;
		current_spr->dist = hypot(s_map->s_player.x_pos - x_spr, s_map->s_player.y_pos - y_spr);
		sprite_size = (PXL_SIZE / current_spr->dist * (s_map->w / 2) / positive_tan(M_PI / 6));

		if (fabs(y_spr - s_map->s_player.y_pos) > 0.00000001)
			diff = s_map->s_player.y_pos - y_spr;
		else
			diff = y_spr - s_map->s_player.y_pos;
    	sprite_dir = atan2(diff, x_spr - s_map->s_player.x_pos);

		while (sprite_dir - s_map->s_ray->fov_angle > M_PI)
			sprite_dir -= 2 * M_PI; 
		while (sprite_dir - s_map->s_ray->fov_angle < -M_PI)
			sprite_dir += 2 * M_PI;
		draw_sprite(s_map, sprite_size, sprite_dir, current_spr->dist, dists);
	}
	// sprite_size = (float)s_map->h / current_spr->dist * 64;
}