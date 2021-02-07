#include "../includes/cub3D.h"

// int     offset = (y * line_length + x * (bits_per_pixel / 8));

void	pxl_put(t_img *data, int x, int y, int color, int pxl_size)
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

void	map_drawer(t_img s_img, t_map_info *s_map_info)
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
				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, WALL_COLOR, PXL_SIZE);
			else if (s_map_info->map[y][x] == '2')
				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, SPRITE_COLOR, PXL_SIZE);
			else if (s_map_info->map[y][x] == '0')
				pxl_put(&s_img, x * PXL_SIZE, y * PXL_SIZE, FLOOR_COLOR, PXL_SIZE);
			x++;
		}
		y++;
	}
}

void	player_drawer(t_img s_img, t_player_info s_player_info)
{
	// write(1,"&",1);
	// pxl_put(&s_img, s_player_info->x_pos * pxl_size, s_player_info->x_pos * pxl_size,  0x00FF0000, pxl_size);
	pxl_put(&s_img, s_player_info.x_pos, s_player_info.y_pos, 0x00FF0000, PLAYER_SIZE);
	// write(1,")",1);
}

int redrawer(int keycode, t_map_info *s_map_info)
{
	// t_player_info	*s_player_info;

	if (keycode == 'w' || keycode == 'a' ||
		keycode == 's' || keycode == 'd')
	{
		// s_map_info->s_player_info.x_pos += s_map_info->pxl_size;
		if (keycode == 'w')
			s_map_info->s_player_info.y_pos -= PLAYER_STEP;
		else if (keycode == 's')
			s_map_info->s_player_info.y_pos += PLAYER_STEP;
		else if (keycode == 'd')
			s_map_info->s_player_info.x_pos += PLAYER_STEP;
		else
			s_map_info->s_player_info.x_pos -= PLAYER_STEP;
		map_drawer(s_map_info->s_img, s_map_info);
		player_drawer(s_map_info->s_img, s_map_info->s_player_info);
		mlx_put_image_to_window(s_map_info->mlx, s_map_info->win, s_map_info->s_img.img, 0, 0);
	}
	return (1);
}

void	make_map_image(t_map_info *s_map_info)
{
	t_img	s_img;


	s_map_info->s_player_info.x_pos = 0;
	s_map_info->s_player_info.y_pos = 0;
	s_img.img = mlx_new_image(s_map_info->mlx, 1000, 600);
	s_img.addr = mlx_get_data_addr(s_img.img, &s_img.bit_per_pixel, &s_img.line_len, &s_img.endian);
	map_drawer(s_img, s_map_info);
	player_drawer(s_img, s_map_info->s_player_info);
	mlx_put_image_to_window(s_map_info->mlx, s_map_info->win, s_img.img, 0, 0);
	s_map_info->s_img = s_img;
	mlx_hook(s_map_info->win, 2, 1L<<0, redrawer, s_map_info);
	
}