/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:43:49 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:43:52 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	painter(t_map *s_map)
{
	t_ray s_ray;

	s_map->s_ray = &s_ray;
	s_ray.fov_angle = dir_to_degree(s_map->s_player);
	s_ray.alpha = change_degree(s_ray.fov_angle, M_PI / 6, -1);
	s_map->mlx = mlx_init();
	s_map->win = mlx_new_window(s_map->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	main_drawer(s_map);
	mlx_loop(s_map->mlx);
}
