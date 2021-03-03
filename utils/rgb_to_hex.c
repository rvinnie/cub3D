/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:22:22 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/03 11:22:23 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned long	rgb_to_hex(t_map *s_map, char *rgb)
{
	int r;
	int g;
	int b;
	char **arr_color;

	if (!(arr_color = ft_split(rgb, ',')))
		put_error(s_map, NULL, 4);
	if (!arr_color[0] || !arr_color[1] || !arr_color[2])
		put_error(s_map, arr_color, 5);
	r = ft_atoi(arr_color[0]);
	g = ft_atoi(arr_color[1]);
	b = ft_atoi(arr_color[2]);
	free_arr(arr_color);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
