#include "../includes/cub3D.h"

// int     offset = (y * line_length + x * (bits_per_pixel / 8));

void	pxl_put(t_address *data, int x, int y, int color, int pxl_size)
{
	char *dst;
	int i;
	int j;

	i = 0;
	while (i < pxl_size)
	{
		j = 0;
		while (j < pxl_size)
		{
			dst = data->addr + ((y + i) * data->line_len + (x + j) * (data->bit_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}

void	map_drawer(t_address img, t_map_info *s_map_info, int pxl_size)
{
	int x;
	int y;

	y = 0;
	while (y < s_map_info->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(s_map_info->map[y]))
		{
			if (s_map_info->map[y][x] == '1')
				pxl_put(&img, x * pxl_size, y * pxl_size, WALL_COLOR, pxl_size);
			else if (s_map_info->map[y][x] == '2')
				pxl_put(&img, x * pxl_size, y * pxl_size, SPRITE_COLOR, pxl_size);
			else if (s_map_info->map[y][x] == '0')
				pxl_put(&img, x * pxl_size, y * pxl_size, FLOOR_COLOR, pxl_size);
			x++;
		}
		y++;
	}
}

void	make_map_image(t_map_info *s_map_info)
{
	int			pxl_size;
	t_address	img;

	pxl_size = 10;
	img.img = mlx_new_image(s_map_info->mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
	map_drawer(img, s_map_info, pxl_size);
	mlx_put_image_to_window(s_map_info->mlx, s_map_info->win, img.img, 0, 0);
}