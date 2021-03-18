/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:15:32 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/23 15:15:34 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_first_horisontal_wall(t_ray *s_ray, t_player *s_player)
{
	double		first_h_x;
	double		first_h_y;
	long int	x_pos;
	long int	y_pos;

	x_pos = s_player->x_pos;
	y_pos = s_player->y_pos;
	if (s_ray->alpha >= 0 && s_ray->alpha <= M_PI)
		first_h_y = (int)(y_pos / PXL_SIZE) * PXL_SIZE - .00000000001;
	else
		first_h_y = (int)(y_pos / PXL_SIZE) * PXL_SIZE + PXL_SIZE;
	first_h_x = x_pos + (y_pos - first_h_y) / tan(s_ray->alpha);
	s_ray->cur_h_x = first_h_x;
	s_ray->cur_h_y = first_h_y;
}

void	find_horisontal_wall(t_ray *s_ray, t_map *s_map)
{
	double		y_dist;
	double		x_dist;
	int			is_wall_x;
	int			is_wall_y;

	find_first_horisontal_wall(s_ray, &(s_map->s_player));
	while (INFINITY_LOOP)
	{
		is_wall_x = s_ray->cur_h_x / PXL_SIZE;
		is_wall_y = s_ray->cur_h_y / PXL_SIZE;
		check_border(s_map, &is_wall_y, &is_wall_x);
		if (s_map->map[is_wall_y][is_wall_x] == '1')
			break ;
		y_dist = s_ray->alpha >= 0 && s_ray->alpha <= M_PI ?
										-PXL_SIZE : PXL_SIZE;
		x_dist = PXL_SIZE / positive_tan(s_ray->alpha);
		if (s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2)
			x_dist *= -1;
		s_ray->cur_h_x += x_dist;
		s_ray->cur_h_y += y_dist;
	}
	s_ray->hor_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2)
							+ pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	s_ray->hor_wall_x = s_ray->cur_h_x;
	s_ray->hor_wall_y = s_ray->cur_h_y;
}

void	find_first_vertical_wall(t_ray *s_ray, t_player *s_player)
{
	double		first_h_x;
	double		first_h_y;
	long int	x_pos;
	long int	y_pos;

	x_pos = s_player->x_pos;
	y_pos = s_player->y_pos;
	if (s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2)
		first_h_x = (int)(x_pos / PXL_SIZE) * PXL_SIZE - .00000000001;
	else
		first_h_x = (int)(x_pos / PXL_SIZE) * PXL_SIZE + PXL_SIZE;
	first_h_y = y_pos + (x_pos - first_h_x) * tan(s_ray->alpha);
	s_ray->cur_h_x = first_h_x;
	s_ray->cur_h_y = first_h_y;
}

void	find_vertical_wall(t_ray *s_ray, t_map *s_map)
{
	double		y_dist;
	double		x_dist;
	int			is_wall_x;
	int			is_wall_y;

	find_first_vertical_wall(s_ray, &(s_map->s_player));
	while (INFINITY_LOOP)
	{
		is_wall_x = s_ray->cur_h_x / PXL_SIZE;
		is_wall_y = s_ray->cur_h_y / PXL_SIZE;
		x_dist = s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2 ?
													-PXL_SIZE : PXL_SIZE;
		y_dist = PXL_SIZE * positive_tan(s_ray->alpha);
		if (s_ray->alpha >= 0 && s_ray->alpha <= M_PI)
			y_dist *= -1;
		check_border(s_map, &is_wall_y, &is_wall_x);
		if (s_map->map[is_wall_y][is_wall_x] == '1')
			break ;
		s_ray->cur_h_x += x_dist;
		s_ray->cur_h_y += y_dist;
	}
	s_ray->ver_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2)
							+ pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	s_ray->ver_wall_x = s_ray->cur_h_x;
	s_ray->ver_wall_y = s_ray->cur_h_y;
}
