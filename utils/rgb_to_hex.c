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

int				check_digit(char **arr_color)
{
	int		i;
	int		j;
	char	*cur_digit;

	i = 0;
	while (arr_color[i])
	{
		j = 0;
		cur_digit = arr_color[i];
		while (cur_digit[j])
		{
			if (!(cur_digit[j] >= '0' && cur_digit[j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char			**check_color_valid(t_map *s_map, char *rgb)
{
	char	**arr_color;

	if (!(arr_color = ft_split(rgb, ',')))
		put_error(s_map, NULL, 4);
	if (!arr_color[0] || !arr_color[1] || !arr_color[2])
	{
		free_hidden_arr(arr_color, 3);
		put_error(s_map, NULL, 5);
	}
	if (!check_digit(arr_color))
	{
		free_hidden_arr(arr_color, 3);
		put_error(s_map, NULL, 5);
	}
	return (arr_color);
}

unsigned long	rgb_to_hex(t_map *s_map, char *rgb)
{
	int		r;
	int		g;
	int		b;
	char	**arr_color;

	arr_color = check_color_valid(s_map, rgb);
	r = ft_atoi(arr_color[0]);
	g = ft_atoi(arr_color[1]);
	b = ft_atoi(arr_color[2]);
	if (r > 256)
		r = 256;
	if (g > 256)
		g = 256;
	if (b > 256)
		b = 256;
	free_hidden_arr(arr_color, 3);
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
