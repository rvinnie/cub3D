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

void	texture_slice(t_map *s_map, int slice_height, int slice_x, unsigned long color)
{
	// int 	texture_x;
	// int 	texture_y;
	int		start_point;
	// char	*filename = "/Users/rvinnie/Desktop/cub3d/textures/cat.xpm";

	// s_map->s_img.img = mlx_xpm_file_to_image(s_map->mlx, filename, &texture_x, &texture_y);
	// s_map->s_img.addr = mlx_get_data_addr(s_map->s_img.img, &s_map->s_img.bit_per_pixel, &s_map->s_img.line_len, &s_map->s_img.endian);
	start_point = SCREEN_HEIGHT / 2 - slice_height / 2;
	
	while (slice_height--)
	{
		pxl_put(&(s_map->s_img), slice_x, start_point, color, 1); //*((unsigned *)text_img.addr + texture_x * x) // 0x00FFFFFF
		start_point++;
	}
	// mlx_destroy_image(s_map->mlx, &text_img);
}

void	drawing_walls(t_map *s_map, t_ray *s_ray, int x)
{
	double			dist_to_wall;
	int				slice_height;
	double			fishbowl_val;
	unsigned long int color = 0x00FFFFFF;
	int clear = 0;

	fishbowl_val = positive_cos(abs(SCREEN_WIDTH / 2 - (x + 1)) * (M_PI / (3 * (SCREEN_WIDTH))));
	// if (fishbowl_val == 0)
		// fishbowl_val = 1;
	if (s_ray->hor_dist < s_ray->ver_dist)
	{
		// printf("\n!horizontal!\n");
		dist_to_wall = s_ray->hor_dist;
		color = 0x00E0E0E0;
	}
	else
	{
		// printf("\n!vertical!\n");
		// printf("hor: %f\n", s_ray->hor_dist);
		// printf("ver: %f\n", s_ray->ver_dist);
		dist_to_wall = s_ray->ver_dist;
	}
	dist_to_wall *= fishbowl_val;
	if (dist_to_wall == 0)
		dist_to_wall = 1;
	slice_height = 2 * round(64 * 277 / dist_to_wall);
	if (slice_height > SCREEN_HEIGHT)
		slice_height = SCREEN_HEIGHT;
	while (clear < SCREEN_HEIGHT)
	{
		pxl_put(&(s_map->s_img), x, clear, 0x00000000, 1);
		clear++;
	}
	texture_slice(s_map, slice_height, x, color);
	// start_point = SCREEN_HEIGHT / 2 - slice_height / 2;
	// while (slice_height--)
	// {
	// 	// write(1,"^",1);
	// 	pxl_put(&(s_map->s_img), x, start_point, color, 1);
	// 	start_point++;
	// }
}

void	raycasting(t_map *s_map, t_ray *s_ray)
{
	// find_horisontal_wall(s_ray, s_map);
	// find_vertical_wall(s_ray, s_map);
	// draw_line(s_ray, s_map, s_ray->alpha);

	// t_img	s_img;

	// s_img.img = mlx_new_image(s_map->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	int x = 0;

	while (x < SCREEN_WIDTH)
	{
		find_horisontal_wall(s_ray, s_map);
		find_vertical_wall(s_ray, s_map);
		// draw_line(s_ray, s_map, s_ray->alpha);
		if (x == SCREEN_WIDTH / 2)
			s_ray->fov_angle = change_degree(s_ray->alpha, M_PI / (320 * 2), 1);
		drawing_walls(s_map, s_ray, x);
		s_ray->alpha = change_degree(s_ray->alpha, M_PI / (3 * SCREEN_WIDTH), 1);
		x++;
	}
	s_ray->alpha = change_degree(s_ray->alpha, M_PI * (SCREEN_WIDTH) / (3 * SCREEN_WIDTH), -1);
	
	// mlx_put_image_to_window(s_map->mlx, s_map->win, s_img.img, 0, 0);
	// printf("hor: %f\n", s_ray->hor_dist);
	// printf("pos_x: %f\npos_y: %f\n", s_map->s_player.x_pos, s_map->s_player.y_pos);
	// printf("alpha %f\n", s_map->s_ray->alpha);
	// printf("hor coord: (%zu, %zu)\n", s_ray->hor_wall_x, s_ray->hor_wall_y);
	// printf("ver: %f\n", s_ray->ver_dist);
	// printf("ver coord: (%zu, %zu)\n\n", s_ray->ver_wall_x, s_ray->ver_wall_y);
}