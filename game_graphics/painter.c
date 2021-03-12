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

void	painter(t_map *s_map, int screenshot)
{
	t_ray s_ray;

	s_map->s_ray = &s_ray;
	s_ray.fov_angle = dir_to_degree(s_map->s_player);
	s_ray.alpha = change_degree(s_ray.fov_angle, M_PI / 6, 1);
	main_drawer(s_map, screenshot);
	if (!screenshot)
		mlx_loop(s_map->mlx);
	else
		printf("screenshot\n");
}
