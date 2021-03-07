/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:19:52 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/09 10:19:54 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	drawing_walls(t_map *s_map, t_ray *s_ray, int x)
{
	double			dist_to_wall;
	double			slice_height;
	double			fishbowl_val;
	double			side_dist;

	fishbowl_val = cos(s_map->s_ray->fov_angle - s_map->s_ray->alpha);
	if (s_ray->hor_dist < s_ray->ver_dist)
	{
		dist_to_wall = s_ray->hor_dist;
		side_dist = s_ray->hor_wall_x;
	}
	else
	{
		dist_to_wall = s_ray->ver_dist;
		side_dist = s_ray->ver_wall_y;
	}
	dist_to_wall *= fishbowl_val;
	if (dist_to_wall == 0)
		dist_to_wall = 1;
	slice_height = (PXL_SIZE / dist_to_wall * (s_map->w / 2) / positive_tan(M_PI / 6));
	texture_slice(s_map, slice_height, x, side_dist);
}

void	raycasting(t_map *s_map, t_ray *s_ray)
{
	int	x;

	x = 0;
	while (x < s_map->w)
	{
		find_horisontal_wall(s_ray, s_map);
		find_vertical_wall(s_ray, s_map);
		drawing_walls(s_map, s_ray, x);
		s_ray->alpha = change_degree(s_ray->alpha, M_PI / (3 * s_map->w), -1);
		x++;
	}
	s_ray->alpha = change_degree(s_ray->alpha, M_PI * (s_map->w) / (3 * s_map->w), 1);
}