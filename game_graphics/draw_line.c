/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 01:15:27 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/11 01:15:29 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_line(t_ray *s_ray, t_map *s_map, double alpha)
{
	int last_x;
	int last_y;
	int flag = 0;
	double cur_x;
	double cur_y;
	long int color = 0x00FF00FF;
	// int 	condition;
	double y_dist;
	double x_dist;

	if (s_ray->hor_dist < s_ray->ver_dist)
	{
		last_x = s_ray->hor_wall_x;
		last_y = s_ray->hor_wall_y;
		color =  0x0000FFFF;
		flag = 1;
	}
	else
	{
		last_x = s_ray->ver_wall_x;
		last_y = s_ray->ver_wall_y;
		flag = 2;
	}
	cur_x = s_map->s_player.x_pos;
	cur_y = s_map->s_player.y_pos;
	if (flag == 1)
	{

		while (cur_x != last_x && cur_y != last_y)
		{
			y_dist = 1;
			if (alpha >= 0 && alpha <= M_PI)
				y_dist = -1;
			x_dist = 1 / positive_tan(alpha);                         
			if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
				x_dist *= -1;
			cur_y += y_dist;
			cur_x += x_dist;
			pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, color, 1);
		}
	}
	else
	{
		while (cur_x != last_x && cur_y != last_y)
		{
			x_dist = 1;
			if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
				x_dist = -1;
			y_dist = 1 * positive_tan(alpha);
			if (alpha >= 0 && s_ray->alpha <= M_PI)
				y_dist *= -1;
			cur_y += y_dist;
			cur_x += x_dist;
			pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, color, 1);
		}
	}
}
