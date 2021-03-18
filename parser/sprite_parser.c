/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:19:26 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/15 12:19:27 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		find_count_spr(char **map, int map_height)
{
	int		i;
	int		j;
	int		count;
	int		cur_len;
	char	let;

	i = 0;
	count = 0;
	while (i < map_height)
	{
		j = 0;
		cur_len = ft_strlen(map[i]);
		while (j < cur_len)
		{
			let = map[i][j];
			if (let == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

t_spr	*create_sprite(t_map *s_map, t_spr **arr_spr, int x, int y)
{
	t_spr	*cur_spr;

	if (!(cur_spr = (t_spr *)ft_calloc(1, sizeof(t_spr))))
	{
		free(arr_spr);
		put_error(s_map, NULL, 4, 2);
	}
	cur_spr->x_pos = x * PXL_SIZE + PXL_SIZE / 2;
	cur_spr->y_pos = y * PXL_SIZE + PXL_SIZE / 2;
	return (cur_spr);
}

void	find_sprites(t_map *s_map)
{
	int		x;
	int		y;
	int		count;
	char	let;
	t_spr	**arr_spr;

	y = 0;
	count = 0;
	if (!(arr_spr = (t_spr **)ft_calloc(s_map->count_spr, sizeof(t_spr *))))
		put_error(s_map, NULL, 4, 2);
	while (y < s_map->map_height)
	{
		x = 0;
		while (s_map->map[y][x])
		{
			let = s_map->map[y][x];
			if (let == '2')
				arr_spr[count++] = create_sprite(s_map, arr_spr, x, y);
			x++;
		}
		y++;
	}
	s_map->s_spr = arr_spr;
}

t_text	*get_sprite(t_map *s_map, char *filename)
{
	t_text	*s_spr_info;
	t_img	*text_img;

	if (!(s_spr_info = (t_text *)ft_calloc(1, sizeof(t_text))))
		put_error(s_map, NULL, 4, 3);
	if (!(text_img = (t_img *)ft_calloc(1, sizeof(t_img))))
		put_error(s_map, NULL, 4, 4);
	if (open(filename, O_RDONLY) == -1)
	{
		free(text_img);
		put_error(s_map, NULL, 2, 3);
	}
	text_img->img = mlx_xpm_file_to_image(s_map->mlx, filename,
		&s_spr_info->width, &s_spr_info->height);
	text_img->addr = mlx_get_data_addr(text_img->img,
		&text_img->bit_per_pixel, &text_img->line_len, &text_img->endian);
	s_spr_info->addr = text_img->addr;
	free(text_img);
	return (s_spr_info);
}
