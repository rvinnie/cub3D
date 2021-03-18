/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:44:19 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:44:20 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_path(char *path, t_map *s_map)
{
	int	flag;

	flag = 0;
	while (*path)
	{
		if (*path == '.')
		{
			path++;
			if (ft_strncmp(path, "cub", 4) == 0)
				flag = 1;
		}
		path++;
	}
	if (flag == 0)
		put_error(s_map, NULL, 6, 0);
}

void	parse_line(t_map *s_map, char *line)
{
	char	**info_arr;

	if (!(info_arr = ft_split(line, ' ')))
	{
		free(line);
		put_error(s_map, NULL, 4, 1);
	}
	choose_info(s_map, info_arr);
	free_arr(info_arr);
}

void	check_doubles(t_map *s_map)
{
	if (s_map->w == 0 || s_map->h == 0 || !s_map->s_parser->no ||
		!s_map->s_parser->so || !s_map->s_parser->ea || !s_map->s_parser->we
		|| !s_map->s_parser->sprite || s_map->s_parser->floor_c == -1 ||
		s_map->s_parser->ceil_c == -1)
		put_error(s_map, NULL, 5, 0);
}

void	get_info(t_map *s_map, int fd)
{
	int		count;
	char	*line;

	if (!(s_map->s_parser = (t_parser *)ft_calloc(1, sizeof(t_parser))))
		put_error(s_map, NULL, 4, 0);
	s_map->w = 0;
	s_map->h = 0;
	s_map->s_parser->floor_c = -1;
	s_map->s_parser->ceil_c = -1;
	s_map->s_parser->no = NULL;
	s_map->s_parser->so = NULL;
	s_map->s_parser->we = NULL;
	s_map->s_parser->ea = NULL;
	s_map->s_parser->sprite = NULL;
	while ((count = get_next_line(fd, &line)))
	{
		if (count == -1)
			put_error(s_map, NULL, 3, 0);
		parse_line(s_map, line);
		free(line);
		line = NULL;
	}
	parse_line(s_map, line);
	free(line);
	check_doubles(s_map);
}

void	main_parser(char *path, t_map *s_map)
{
	int		fd;

	check_path(path, s_map);
	if ((fd = open(path, O_RDONLY)) == -1)
		put_error(s_map, NULL, 2, 0);
	get_info(s_map, fd);
	close(fd);
	if ((fd = open(path, O_RDONLY)) == -1)
		put_error(s_map, NULL, 2, 1);
	get_map(s_map, fd);
	s_map->count_spr = 0;
	find_player(s_map);
	s_map->count_spr = find_count_spr(s_map->map, s_map->map_height);
	s_map->s_text = get_texture(s_map);
	find_sprites(s_map);
	s_map->s_spr_info = get_sprite(s_map, s_map->s_parser->sprite);
	close(fd);
}
