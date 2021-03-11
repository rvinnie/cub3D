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

#include "../includes/cub3d.h"

char	*make_cur_line(char *start_line, int arr_width)
{
	char	*line;
	int		i;
	int		len;

	if (!(line = (char *)ft_calloc(arr_width + 3, sizeof(char))))
		return (NULL);
	len = ft_strlen(start_line);
	i = 0;
	line[i++] = '9';
	while (arr_width--)
	{
		if (i > len)
			line[i] = '0';
		else
			line[i] = start_line[i - 1];
		i++;
	}
	line[i++] = '9';
	line[i] = '\0';
	return (line);
}

char	*make_void_line(int arr_width)
{
	char	*line;
	int		i;

	if (!(line = ft_calloc(arr_width + 3, sizeof(char))))
		return (NULL);
	arr_width += 2;
	i = 0;
	while (arr_width--)
		line[i++] = '9';
	line[i] = '\0';
	return (line);
}

char	**rebuild_arr(t_map *s_map, char **start_arr)
{
	char	**new_arr;
	int		arr_width;
	int		arr_height;
	int		j;

	arr_width = s_map->map_width;
	arr_height = s_map->map_height;
	if (!(new_arr = (char **)ft_calloc(arr_height + 1, sizeof(char *))))
		put_error(s_map, NULL, 4);
	j = 0;
	if (!(new_arr[j++] = make_void_line(arr_width)))
		put_error(s_map, NULL, 4);
	while (arr_height--)
	{
		if (!(new_arr[j] = make_cur_line(start_arr[j - 1], arr_width)))
			put_error(s_map, new_arr, 4);
		j++;
	}
	if (!(new_arr[j] = make_void_line(arr_width)))
		put_error(s_map, NULL, 4);
	return (new_arr);
}

char	**flood_fill(t_map *s_map, char **arr, int cur_x, int cur_y)
{
	if (arr[cur_y][cur_x] == '9')
		put_error(s_map, NULL, 5); // free (arr);
	else if (arr[cur_y][cur_x] == '1' || arr[cur_y][cur_x] == '*')
		return (arr);
	arr[cur_y][cur_x] = '*';
	arr = flood_fill(s_map, arr, cur_x + 1, cur_y);
	arr = flood_fill(s_map, arr, cur_x - 1, cur_y);
	arr = flood_fill(s_map, arr, cur_x, cur_y + 1);
	arr = flood_fill(s_map, arr, cur_x, cur_y - 1);
	return (arr);
}

void	free_hidden_arr(char **arr, int y)
{
	int i;

	i = 0;
	while (y--)
		free(arr[i++]);
	free(arr);
}

void print_arr2(t_map *s_map, char **arr)
{
	int h = s_map->map_height + 2;
	int i = 0;

	while (h--)
		printf("%s\n", arr[i++]);
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
	// print_arr2(s_map, arr);
	free_hidden_arr(arr, s_map->map_height);
}
