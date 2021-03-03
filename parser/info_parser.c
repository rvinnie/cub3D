/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:22:10 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/03 11:22:11 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	resolution_parser(t_map *s_map, char **info_arr)
{
	if (!info_arr[1] || !info_arr[2] || s_map->w != 0)
		put_error(s_map, info_arr, 5);
	s_map->w = ft_atoi(info_arr[1]);
	s_map->h = ft_atoi(info_arr[2]);
}

void	color_parser(t_map *s_map, char **info_arr, char ch)
{	
	char	*tmp;

	if (!info_arr[1])
		put_error(s_map, info_arr, 5);
	if (ch == 'f' && !s_map->s_parser->floor_c)
	{
		if (!(tmp = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
		s_map->s_parser->floor_c = rgb_to_hex(s_map, tmp);
		free(tmp);
	}
	else if (ch == 'c' && !s_map->s_parser->ceil_c)
	{
		if (!(tmp = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
		s_map->s_parser->ceil_c = rgb_to_hex(s_map, tmp);
		free(tmp);
	}
	else
		put_error(s_map, info_arr, 5);
}

void	image_dir_parser(t_map *s_map, char **info_arr, int dir)
{
	if (!info_arr[1])
		put_error(s_map, info_arr, 5);
	if (dir == 0 && !s_map->s_parser->no)
	{
		if (!(s_map->s_parser->no = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
	}
	else if (dir == 1 && !s_map->s_parser->so)
	{
		if (!(s_map->s_parser->so = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
	}
	else if (dir == 2 && !s_map->s_parser->ea)
	{
		if (!(s_map->s_parser->ea = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
	}
	else if (dir == 3 && !s_map->s_parser->we)
	{
		if (!(s_map->s_parser->we = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
	}
	else
		put_error(s_map, info_arr, 5);
}

void	image_spr_parser(t_map *s_map, char **info_arr)
{
	if (!info_arr[1])
		put_error(s_map, info_arr, 5);
	if (!s_map->s_parser->sprite)
	{
		if (!(s_map->s_parser->sprite = ft_strdup(info_arr[1])))
			put_error(s_map, info_arr, 4);
	}
	else
		put_error(s_map, info_arr, 5);
}

void	choose_info(t_map *s_map, char **info_arr)
{
	if (!info_arr[0])
		return ;
	if (ft_strncmp(info_arr[0], "R", 2) == 0)
		resolution_parser(s_map, info_arr);
	else if (ft_strncmp(info_arr[0], "NO", 3) == 0)
		image_dir_parser(s_map, info_arr, 0);
	else if (ft_strncmp(info_arr[0], "SO", 3) == 0)
		image_dir_parser(s_map, info_arr, 1);
	else if (ft_strncmp(info_arr[0], "EA", 3) == 0)
		image_dir_parser(s_map, info_arr, 2);
	else if (ft_strncmp(info_arr[0], "WE", 3) == 0)
		image_dir_parser(s_map, info_arr, 3);
	else if (ft_strncmp(info_arr[0], "S", 3) == 0)
		image_spr_parser(s_map, info_arr);
	else if (ft_strncmp(info_arr[0], "F", 3) == 0)
		color_parser(s_map, info_arr, 'f');
	else if (ft_strncmp(info_arr[0], "C", 3) == 0)
		color_parser(s_map, info_arr, 'c');
	else
	{
		if (is_map_checker(s_map, info_arr) != 1)
			put_error(s_map, info_arr, 5);
	}
}
