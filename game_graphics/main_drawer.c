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

#include "../includes/cub3d.h"

// int     offset = (y * line_length + x * (bits_per_pixel / 8));

void	pxl_put(t_img *data, int x, int y, int color, int pxl_size)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	while (i < pxl_size)
	{
		j = 0;
		while (j < pxl_size)
		{
			dst = data->addr + ((y + i) * data->line_len + (x + j) * (data->bit_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}

// void	map_drawer(t_img s_img, t_map *s_map)
// {
// 	int		x;
// 	int		y;
// 	char	cur_ch;

// 	y = 0;
// 	while (y < s_map->map_height)
// 	{
// 		x = 0;
// 		while (x < (int)ft_strlen(s_map->map[y]))
// 		{
// 			cur_ch = s_map->map[y][x];
// 			if (cur_ch == '1')
// 				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, WALL_COLOR, PXL_SIZE);
// 			else if (cur_ch == '2')
// 				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, SPRITE_COLOR, PXL_SIZE);
// 			else if (find_chr(cur_ch, "0NSWE"))
// 				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, FLOOR_COLOR, PXL_SIZE);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	player_drawer(t_img s_img, t_player s_player)
// {
// 	pxl_put(&s_img, s_player.x_pos, s_player.y_pos, 0x00FF0000, PLAYER_SIZE);
// }

int		exit_game(t_map *s_map)
{
	exit(1);
	s_map->h = s_map->h;
}

int		click_handler(int keycode, t_map *s_map)
{
	// printf("%d\n",keycode);

	if (keycode == 65307) // 53 
		exit_game(s_map); // don't forget valid exit
	if (keycode == 65363) //124 left rotate 65363
	{
		s_map->s_ray->alpha = change_degree(s_map->s_ray->alpha, M_PI / 60, -1); // M_PI / (3 * 320)
		s_map->s_ray->fov_angle = change_degree(s_map->s_ray->fov_angle, M_PI / 60, -1);
	}
	else if (keycode == 65361) //123 right rotate 65361
	{
		s_map->s_ray->alpha = change_degree(s_map->s_ray->alpha, M_PI / 60, 1);
		s_map->s_ray->fov_angle = change_degree(s_map->s_ray->fov_angle, M_PI / 60, 1);
	}
	else if (keycode == 119) // 13 up 119
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'f');
	else if (keycode == 's') // 1 down s
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'b');
	else if (keycode == 'd') // 2 right d
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'r');
	else if (keycode == 'a') // 0 a
		make_step(s_map, &s_map->s_player.x_pos, &s_map->s_player.y_pos, 'l');
	// map_drawer(s_map->s_img, s_map);
	// player_drawer(s_map->s_img, s_map->s_player);
	raycasting(s_map, s_map->s_ray);
	mlx_put_image_to_window(s_map->mlx, s_map->win, s_map->s_img.img, 0, 0);
	return (1);
}

void	main_drawer(t_map *s_map, int screenshot)
{
	t_img	s_img;

	s_img.img = mlx_new_image(s_map->mlx, s_map->w, s_map->h);
	s_img.addr = mlx_get_data_addr(s_img.img, &s_img.bit_per_pixel, &s_img.line_len, &s_img.endian);
	// map_drawer(s_img, s_map);
	// player_drawer(s_img, s_map->s_player);
	s_map->s_img = s_img;
	raycasting(s_map, s_map->s_ray);
	mlx_put_image_to_window(s_map->mlx, s_map->win, s_map->s_img.img, 0, 0);
	if (!screenshot)
	{
		mlx_hook(s_map->win, 2, 1L<<0, click_handler, s_map);
		mlx_hook(s_map->win, 17, 1L<<0, exit_game, s_map);
	}
}
