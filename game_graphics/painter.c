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

#include "../cub3d.h"

void	painter(t_map *s_map, int screenshot, char *third_arg)
{
	t_ray s_ray;

	s_map->s_ray = &s_ray;
	s_ray.fov_angle = dir_to_degree(s_map->s_player);
	s_ray.alpha = change_degree(s_ray.fov_angle, M_PI / 6, 1);
	main_drawer(s_map, screenshot);
	if (screenshot)
	{
		if (!check_third_arg(third_arg))
			put_error(s_map, NULL, 7, 6);
		make_screenshot(s_map, s_map->s_img);
	}
	else
		mlx_loop(s_map->mlx);
}
