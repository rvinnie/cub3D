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
	int clear = 0;

	fishbowl_val = fishbowl_handler(s_ray->alpha);
	if (s_ray->hor_dist < s_ray->ver_dist)
		dist_to_wall = s_ray->hor_dist;
	else
		dist_to_wall = s_ray->ver_dist;
	dist_to_wall *= fishbowl_val;
	slice_height = round(dist_to_wall * 64 / 277);
	start_point = 100 - slice_height / 2;
	// printf("@@@@%f\n", round(64 / 277 * dist_to_wall));
	while (clear < 200)
	{
		pxl_put(&(s_map->s_img), x, clear, 0x00000000, 1);
		clear++;
	}
	while (slice_height--)
	{
		// write(1,"^",1);
		pxl_put(&(s_map->s_img), x, start_point, 0x00FFFFFF, 1);
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

	s_img.img = mlx_new_image(s_map->mlx, 320, 200);
	int x = 0;

	while (x < 320)
	{
		find_horisontal_wall(s_ray, s_map);
		find_vertical_wall(s_ray, s_map);
		// draw_line(s_ray, s_map, s_ray->alpha);
		drawing_walls(s_map, s_ray, x);
		s_ray->alpha = change_degree(s_ray->alpha, M_PI / (3 * 320), 1);
		x++;
	}
	s_ray->alpha = change_degree(s_ray->alpha, M_PI * 319 / (3 * 320), -1);


	mlx_put_image_to_window(s_map->mlx, s_map->win, s_img.img, 0, 0);
	printf("\ndist_hor: %f\n", s_ray->hor_dist);
	printf("hor coord: (%zu, %zu)\n", s_ray->hor_wall_x, s_ray->hor_wall_y);
	printf("dist_ver: %f\n", s_ray->ver_dist);
	printf("ver coord: (%zu, %zu)\n\n", s_ray->ver_wall_x, s_ray->ver_wall_y);
    // 1) Based on the viewing angle, subtract 30 degrees (half of the FOV).
    // 2) Starting from column 0:
    //  a) Cast a ray.
    //  b) Trace the ray until it hits a wall.
    // 3) Record the distance to the wall (the distance is equal to the length of the ray).
    // 4) Add the angle increment so that the ray moves to the right (we know from Figure 10 that the value of the angle increment is 60/320 degrees).
    // 5) Repeat step 2 and 3 for each subsequent column until all 320 rays are cast.
}