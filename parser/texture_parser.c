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

char	*get_filename(int	count)
{
	char	*filename;
	if (count == 0)
		filename = "/Users/rvinnie/Desktop/cub3d/textures/cats/kapusta.xpm";
		// filename = "/Users/rvinnie/Desktop/cub3d/textures/wolf_textures/wall_n.xpm";
	else if (count == 1)
		filename = "/Users/rvinnie/Desktop/cub3d/textures/cats/kapusta.xpm";
	else if (count == 2)
		filename = "/Users/rvinnie/Desktop/cub3d/textures/cats/kapusta.xpm";
	else
		filename = "/Users/rvinnie/Desktop/cub3d/textures/cats/kapusta.xpm";
	return (filename);
}

t_text	**get_texture(t_map *s_map)
{
	t_text	**arr_text;
	t_img	*text_img;
	int		count;

	if (!(arr_text = (t_text **)malloc(sizeof(t_text *) * 4)))
		put_error(s_map, NULL, 4);
	count = 0;
	while (count < 4)
	{
		if (!(arr_text[count] = (t_text *)malloc(sizeof(t_text))))
		{
			free(arr_text);
			put_error(s_map, NULL, 4);
		}
		if (!(text_img = (t_img *)malloc(sizeof(t_img))))
		{
			free(arr_text[count]);
			put_error(s_map, NULL, 4);
		}
		text_img->img = mlx_xpm_file_to_image(s_map->mlx, get_filename(count),
						&arr_text[count]->width, &arr_text[count]->height);
		text_img->addr = mlx_get_data_addr(text_img->img, &text_img->bit_per_pixel,
						&text_img->line_len, &text_img->endian);
		arr_text[count]->addr = text_img->addr;
		free(text_img);
		count++;
	}
	return(arr_text);
}
