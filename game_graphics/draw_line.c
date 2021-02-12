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

// void	ray_drawer(t_draw_ray *s_draw_ray, double alpha, t_img *s_img)
// {

// // }

void	make_extra_horizont(double alpha, int diff, t_map *s_map, double cur_x, double cur_y)
{
	int	x_dist;
	if (fabs(alpha - M_PI * 2) < 0.00001)
		x_dist = 1;
	else
		x_dist = -1;
	while (diff--)
	{
		cur_x += x_dist;
		pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, 0x00FF00FF, 1);
	}
}

void	make_extra_vertical(double alpha, int diff, t_map *s_map, double cur_x, double cur_y)
{
	int	y_dist;

	if (fabs(alpha - M_PI * 3 / 2) < 0.00001)
		y_dist = 1;
	else
		y_dist = -1;
	while (diff--)
	{
		cur_y += y_dist;
		pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, 0x00FF00FF, 1);
	}
}

void	draw_line(t_ray *s_ray, t_map *s_map, double alpha)
{
	int last_x;
	int last_y;
	int flag = 0;
	double cur_x;
	double cur_y;
	// int 	condition;
	double y_dist;
	double x_dist;

	if (s_ray->hor_dist < s_ray->ver_dist)
	{
		last_x = s_ray->hor_wall_x;
		last_y = s_ray->hor_wall_y;
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
	// printf("%f\n", 180 * alpha / M_PI);
	// printf("(%d,%d)\n",(int)cur_x, (int)cur_y);
	if (flag == 1)
	{
		if (fabs(alpha - M_PI / 2) < 0.00001 || fabs(alpha - 3 * M_PI / 2) < 0.00001)
			printf("\n%ld\n", s_ray->ver_wall_y);
			// make_extra_vertical(alpha, fabs(s_ray->ver_wall_y - cur_y), s_map, cur_x, cur_y);
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
			pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, 0x00FF00FF, 1);
		}
	}
	else
	{
		if (fabs(alpha - M_PI * 2) < 0.00001 || fabs(alpha - M_PI) < 0.00001)
			make_extra_horizont(alpha, fabs(s_ray->ver_wall_x - cur_x), s_map, cur_x, cur_y);
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
			pxl_put(&s_map->s_img, (int)cur_x, (int)cur_y, 0x00FF00FF, 1);
		}
	}
}
