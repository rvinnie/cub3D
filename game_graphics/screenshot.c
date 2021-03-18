/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:28:42 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/15 10:28:46 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_third_arg(char *third_arg)
{
	if (ft_strncmp(third_arg, "--save", 7) == 0)
		return (1);
	return (0);
}

char	*put_info(char *buff, int w, int h)
{
	int size;

	size = 54 + w * h * 4;
	while (w % 4 != 0)
		w--;
	ft_memset(buff, 0, 54);
	buff[0] = 'B';
	buff[1] = 'M';
	buff[2] = size;
	buff[3] = size >> 8;
	buff[4] = size >> 16;
	buff[5] = size >> 24;
	buff[10] = 54;
	buff[14] = 40;
	buff[18] = w;
	buff[19] = w >> 8;
	buff[20] = w >> 16;
	buff[21] = w >> 24;
	buff[22] = h;
	buff[23] = h >> 8;
	buff[24] = h >> 16;
	buff[25] = h >> 24;
	buff[26] = 1;
	buff[28] = 24;
	return (buff);
}

void	put_screenshot(int fd, t_img s_img, int width, int height)
{
	int x;
	int color;

	height--;
	while (height >= 0)
	{
		x = 0;
		while (x < width)
		{
			color = *(int *)(s_img.addr + (height * s_img.line_len + x *
											(s_img.bit_per_pixel / 8)));
			write(fd, &color, 3);
			x++;
		}
		height--;
	}
}

void	make_screenshot(t_map *s_map, t_img s_img)
{
	int		fd;
	int		w;
	int		h;
	char	buff[54];

	w = s_map->w;
	h = s_map->h;
	fd = open("screenshot.bmp", O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0666);
	write(fd, put_info(buff, w, h), 54);
	put_screenshot(fd, s_img, w, h);
	close(fd);
	exit_game(s_map, 6);
}
