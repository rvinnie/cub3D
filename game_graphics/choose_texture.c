/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:13:33 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/17 17:13:34 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		choose_texture_second(char hit_dir, char alpha_dir_h, char alpha_dir_v)
{
	int		count;

	count = 0;
	if (hit_dir == 'h')
	{
		if (alpha_dir_h == '+')
			count = 0;
		else
			count = 1;
	}
	else
	{
		if (alpha_dir_v == '-')
			count = 2;
		else
			count = 3;
	}
	return (count);
}

t_text	choose_texture(t_map *s_map)
{
	char	alpha_dir_h;
	char	alpha_dir_v;
	char	hit_dir;
	double	alpha;
	int		count;

	alpha = s_map->s_ray->alpha;
	if (s_map->s_ray->hor_dist < s_map->s_ray->ver_dist)
		hit_dir = 'h';
	else
		hit_dir = 'v';
	if (alpha >= 0 && alpha <= M_PI)
		alpha_dir_h = '+';
	else
		alpha_dir_h = '-';
	if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
		alpha_dir_v = '-';
	else
		alpha_dir_v = '+';
	count = choose_texture_second(hit_dir, alpha_dir_h, alpha_dir_v);
	return (*s_map->s_text[count]);
}
