/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hanler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 13:07:11 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/15 13:07:14 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ver_spr_line(t_map *s_map, t_spr *spr, double *dists,
													double x_text)
{
	int		color;
	double	spr_size;
	double	y_text;

	y_text = 0;
	spr_size = spr->spr_size;
	while (spr->j < spr_size)
	{
		if (spr->v_off + spr->j > s_map->h - 1 ||
			spr->v_off + spr->j < -(spr_size))
			break ;
		color = *((unsigned int*)s_map->s_spr_info->addr +
			((int)y_text * s_map->s_spr_info->width + (int)x_text));
		if (color != 0 && dists[(int)(spr->h_off + spr->i)] >= spr->dist &&
													spr->h_off + spr->i > 0)
			pxl_put(&(s_map->s_img), spr->h_off + spr->i,
							spr->v_off + spr->j, color);
		spr->j++;
		y_text += spr->y_step;
	}
}

void	draw_sprite(t_map *s_map, t_spr *spr, double *dists)
{
	double	x_text;

	spr->i = 0;
	x_text = 0;
	while (spr->i < spr->spr_size)
	{
		if ((int)(spr->h_off + spr->i) > s_map->w ||
			(int)(spr->h_off + spr->i) < -(int)spr->spr_size)
			break ;
		spr->j = 0;
		draw_ver_spr_line(s_map, spr, dists, x_text);
		x_text += spr->x_step;
		spr->i++;
	}
}

void	set_sprite_info(t_map *s_map, t_spr *spr)
{
	spr->h_off = (s_map->s_ray->fov_angle - spr->spr_dir) / (M_PI / 3) *
					(s_map->w) + (s_map->w / 2) - (spr->spr_size / 2);
	spr->v_off = s_map->h / 2 - spr->spr_size / 2;
	spr->y_step = s_map->s_spr_info->height / spr->spr_size;
	spr->x_step = s_map->s_spr_info->width / spr->spr_size;
}

void	sprite_handler(t_map *s_map, double *dists)
{
	t_spr			*cur_spr;
	int				i;
	double			diff;

	i = 0;
	while (i < s_map->count_spr)
	{
		cur_spr = s_map->s_spr[i++];
		cur_spr->spr_size = (PXL_SIZE / cur_spr->dist * (s_map->w / 2) /
												positive_tan(M_PI / 6));
		if (fabs(cur_spr->y_pos - s_map->s_player.y_pos) > 0.00000001)
			diff = s_map->s_player.y_pos - cur_spr->y_pos;
		else
			diff = cur_spr->y_pos - s_map->s_player.y_pos;
		cur_spr->spr_dir = atan2(diff, cur_spr->x_pos - s_map->s_player.x_pos);
		while (cur_spr->spr_dir - s_map->s_ray->fov_angle > M_PI)
			cur_spr->spr_dir -= 2 * M_PI;
		while (cur_spr->spr_dir - s_map->s_ray->fov_angle < -M_PI)
			cur_spr->spr_dir += 2 * M_PI;
		set_sprite_info(s_map, cur_spr);
		draw_sprite(s_map, cur_spr, dists);
	}
}
