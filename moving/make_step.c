/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:15:12 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/23 15:15:14 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_wall(t_map *s_map, double x_pos, double y_pos)
{
	int		check_wall_x;
	int		check_wall_y;
	char	**map;

	map = s_map->map;
	check_wall_x = x_pos / PXL_SIZE;
	check_wall_y = y_pos / PXL_SIZE;
	check_border(s_map, &check_wall_y, &check_wall_x);
	if (map[check_wall_y][check_wall_x] == '1' ||
		map[check_wall_y][check_wall_x] == '2')
		return (1);
	return (0);
}

void	horizontal_handler(double *x_diff, double *y_diff,
							double fov_angle, char side)
{
	double	diff_angle;

	if (side == 'r')
		fov_angle = change_degree(fov_angle, M_PI / 2, -1);
	else if (side == 'l')
		fov_angle = change_degree(fov_angle, M_PI / 2, 1);
	if (fov_angle > M_PI)
		diff_angle = fabs(fov_angle - 3 * M_PI / 2);
	else
		diff_angle = fabs(fov_angle - M_PI / 2);
	*x_diff = PLAYER_STEP * positive_sin(diff_angle);
	*y_diff = PLAYER_STEP * positive_cos(diff_angle);
	if (fov_angle >= 0 && fov_angle <= M_PI)
		*y_diff *= -1;
	if (fov_angle >= M_PI / 2 && fov_angle <= 3 * M_PI / 2)
		*x_diff *= -1;
}

void	vertical_handler(double *x_diff, double *y_diff,
						double fov_angle, char side)
{
	double	diff_angle;

	if (side == 'r')
		fov_angle = change_degree(fov_angle, M_PI / 2, -1);
	else if (side == 'l')
		fov_angle = change_degree(fov_angle, M_PI / 2, 1);
	if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
		diff_angle = fabs(fov_angle - M_PI);
	else
		diff_angle = fov_angle;
	*x_diff = PLAYER_STEP * positive_cos(diff_angle);
	*y_diff = PLAYER_STEP * positive_sin(diff_angle);
	if (fov_angle >= 0 && fov_angle <= M_PI)
		*y_diff *= -1;
	if (fov_angle >= M_PI / 2 && fov_angle <= 3 * M_PI / 2)
		*x_diff *= -1;
}

void	make_step(t_map *s_map, double *x_pos, double *y_pos, char side)
{
	double	fov_angle;
	double	x_diff;
	double	y_diff;

	fov_angle = s_map->s_ray->fov_angle;
	if ((fov_angle >= M_PI / 4 && fov_angle < 3 * M_PI / 4) ||
		(fov_angle >= 5 * M_PI / 4 && fov_angle < 7 * M_PI / 4))
		horizontal_handler(&x_diff, &y_diff, fov_angle, side);
	else
		vertical_handler(&x_diff, &y_diff, fov_angle, side);
	if (side == 'b')
	{
		x_diff *= -1;
		y_diff *= -1;
	}
	if (!check_wall(s_map, *x_pos + x_diff, *y_pos))
		*x_pos += x_diff;
	if (!check_wall(s_map, *x_pos, *y_pos + y_diff))
		*y_pos += y_diff;
}
