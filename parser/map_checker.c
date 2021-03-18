/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:12:43 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/11 12:12:44 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*build_void_part(t_map *s_map, char **new_arr, int arr_width, int j)
{
	if (!(new_arr[j] = make_void_line(arr_width)))
	{
		free(new_arr);
		put_error(s_map, NULL, 4, 4);
	}
	return (new_arr[j]);
}

char	**rebuild_arr(t_map *s_map, char **start_arr)
{
	char	**new_arr;
	int		arr_width;
	int		arr_height;
	int		j;

	arr_width = s_map->map_width;
	arr_height = s_map->map_height;
	if (!(new_arr = (char **)ft_calloc(arr_height + 3, sizeof(char *))))
		put_error(s_map, NULL, 4, 4);
	j = 0;
	new_arr[j] = build_void_part(s_map, new_arr, arr_width, j);
	j++;
	while (arr_height--)
	{
		if (!(new_arr[j] = make_cur_line(start_arr[j - 1], arr_width)))
		{
			free(new_arr);
			put_error(s_map, new_arr, 4, 4);
		}
		j++;
	}
	new_arr[j] = build_void_part(s_map, new_arr, arr_width, j);
	return (new_arr);
}

char	**flood_fill(t_map *s_map, char **arr, int cur_x, int cur_y)
{
	if (arr[cur_y][cur_x] == '9')
	{
		free_hidden_arr(arr, s_map->map_height + 2);
		put_error(s_map, NULL, 5, 5);
	}
	else if (arr[cur_y][cur_x] == '1' || arr[cur_y][cur_x] == '*')
		return (arr);
	arr[cur_y][cur_x] = '*';
	arr = flood_fill(s_map, arr, cur_x + 1, cur_y);
	arr = flood_fill(s_map, arr, cur_x - 1, cur_y);
	arr = flood_fill(s_map, arr, cur_x, cur_y + 1);
	arr = flood_fill(s_map, arr, cur_x, cur_y - 1);
	return (arr);
}

void	map_checker(t_map *s_map)
{
	char	**arr;
	int		x_first;
	int		y_first;

	x_first = s_map->s_player.x_pos / 64 + 1;
	y_first = s_map->s_player.y_pos / 64 + 1;
	arr = rebuild_arr(s_map, s_map->map);
	arr = flood_fill(s_map, arr, x_first, y_first);
	free_hidden_arr(arr, s_map->map_height + 2);
}
