/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:44:02 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:44:04 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	pxl_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		click_handler(int keycode, t_map *s_map)
{
	if (keycode == 53)
		exit_game(s_map, 6);
	if (keycode == 124)
	{
		s_map->s_ray->alpha = change_degree(s_map->s_ray->alpha, M_PI / 60, -1);
		s_map->s_ray->fov_angle =
			change_degree(s_map->s_ray->fov_angle, M_PI / 60, -1);
	}
	else if (keycode == 123)
	{
		s_map->s_ray->alpha = change_degree(s_map->s_ray->alpha, M_PI / 60, 1);
		s_map->s_ray->fov_angle =
			change_degree(s_map->s_ray->fov_angle, M_PI / 60, 1);
	}
	else if (keycode == 13)
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'f');
	else if (keycode == 1)
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'b');
	else if (keycode == 2)
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'r');
	else if (keycode == 0)
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'l');
	raycasting(s_map, s_map->s_ray);
	mlx_put_image_to_window(s_map->mlx, s_map->win, s_map->s_img.img, 0, 0);
	return (1);
}

void	main_drawer(t_map *s_map, int screenshot)
{
	t_img	s_img;

	s_img.img = NULL;
	s_img.img = mlx_new_image(s_map->mlx, s_map->w, s_map->h);
	s_img.addr = mlx_get_data_addr(s_img.img, &s_img.bit_per_pixel,
									&s_img.line_len, &s_img.endian);
	s_map->s_img = s_img;
	raycasting(s_map, s_map->s_ray);
	mlx_put_image_to_window(s_map->mlx, s_map->win, s_map->s_img.img, 0, 0);
	if (!screenshot)
	{
		mlx_hook(s_map->win, 2, 1L << 0, click_handler, s_map);
		mlx_hook(s_map->win, 17, 1L << 0, exit_game, s_map);
	}
}
