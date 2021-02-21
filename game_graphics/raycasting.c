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
	int		dist_to_wall;
	int		slice_height;
	int		start_point;
	double	fishbowl_val;
	unsigned long int color = 0x00FFFFFF;
	int clear = 0;

	// fishbowl_val = fishbowl_handler(s_ray->alpha);
	fishbowl_val = positive_cos(abs(SCREEN_WIDTH / 2 - (x + 1)) * (M_PI / (3 * SCREEN_WIDTH)));
	// fishbowl_val = positive_cos(fishbowl_val);
	if (s_ray->hor_dist < s_ray->ver_dist)
	{
		dist_to_wall = s_ray->hor_dist;
		// color = 0x00F0F0F0;
	}
	else
		dist_to_wall = s_ray->ver_dist;
	dist_to_wall *= fishbowl_val;
	slice_height = 2 * round(64 * 277/ dist_to_wall);
	start_point = SCREEN_HEIGHT / 2 - slice_height / 2;
	// printf("@@@@%f\n", round(64 / 277 * dist_to_wall));
	while (clear < SCREEN_HEIGHT)
	{
		pxl_put(&(s_map->s_img), x, clear, 0x00000000, 1);
		clear++;
	}
	while (slice_height--)
	{
		// write(1,"^",1);
		pxl_put(&(s_map->s_img), x, start_point, color, 1);
		start_point++;
	}
	
}

void	raycasting(t_map *s_map, t_ray *s_ray)
{
	// find_horisontal_wall(s_ray, s_map);
	// find_vertical_wall(s_ray, s_map);
	// draw_line(s_ray, s_map, s_ray->alpha);
	// drawing_walls();
	t_img	s_img;

	s_img.img = mlx_new_image(s_map->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	int x = 0;

	while (x < SCREEN_WIDTH)
	{
		find_horisontal_wall(s_ray, s_map);
		find_vertical_wall(s_ray, s_map);
		// draw_line(s_ray, s_map, s_ray->alpha);
		drawing_walls(s_map, s_ray, x);
		s_ray->alpha = change_degree(s_ray->alpha, M_PI / (3 * SCREEN_WIDTH), 1);
		x++;
	}
	s_ray->alpha = change_degree(s_ray->alpha, M_PI * (SCREEN_WIDTH - 1) / (3 * SCREEN_WIDTH), -1);


	mlx_put_image_to_window(s_map->mlx, s_map->win, s_img.img, 0, 0);
	// printf("\ndist_hor: %f\n", s_ray->hor_dist);
	// printf("hor coord: (%zu, %zu)\n", s_ray->hor_wall_x, s_ray->hor_wall_y);
	// printf("dist_ver: %f\n", s_ray->ver_dist);
	// printf("ver coord: (%zu, %zu)\n\n", s_ray->ver_wall_x, s_ray->ver_wall_y);
}