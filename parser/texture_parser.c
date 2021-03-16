/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:53:20 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/02 16:53:22 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_filename(t_map *s_map, int count)
{
	char	*filename;

	if (count == 0)
		filename = s_map->s_parser->no;
	else if (count == 1)
		filename = s_map->s_parser->so;
	else if (count == 2)
		filename = s_map->s_parser->we;
	else
		filename = s_map->s_parser->ea;
	if (open(filename, O_RDONLY) == -1)
		put_error(s_map, NULL, 2);
	return (filename);
}

t_text	**get_texture(t_map *s_map)
{
	t_text	**arr_text;
	t_img	*text_img;
	int		count;

	if (!(arr_text = (t_text **)ft_calloc(4, sizeof(t_text *))))
		put_error(s_map, NULL, 4);
	count = 0;
	while (count < 4)
	{
		if (!(arr_text[count] = (t_text *)ft_calloc(1, sizeof(t_text))))
		{
			free(arr_text);
			put_error(s_map, NULL, 4);
		}
		if (!(text_img = (t_img *)ft_calloc(1, sizeof(t_img))))
		{
			free(arr_text[count]);
			put_error(s_map, NULL, 4);
		}
		text_img->img = mlx_xpm_file_to_image(s_map->mlx, get_filename(s_map,
			count), &arr_text[count]->width, &arr_text[count]->height);
		text_img->addr = mlx_get_data_addr(text_img->img,
			&text_img->bit_per_pixel, &text_img->line_len, &text_img->endian);
		arr_text[count]->addr = text_img->addr;
		free(text_img);
		count++;
	}
	return (arr_text);
}
