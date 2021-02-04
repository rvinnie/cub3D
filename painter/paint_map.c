#include "../includes/cub3D.h"

typedef struct
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}			t_data;

// int     offset = (y * line_length + x * (bits_per_pixel / 8));

void pxl_put(t_data *data, int x, int y, int color)
{
	char *dst;
	int i = 0;
	int j = 0;

	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			dst = data->addr + ((y + i) * data->line_len + (x + j) * (data->bit_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}

void paint_map(t_map_info s_map_info)
{
	void *mlx;
	int x;
	int y = 0;
	int pxl_size = 10;
	void *win;
	t_data img;

	char	**arr = s_map_info.map;
	int		heig = s_map_info.map_height;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);
	while (y < heig)
	{
		x = 0;
		while (x < (int)strlen(arr[y]))
		{
			if (arr[y][x] == '1')
				pxl_put(&img, x * pxl_size, y * pxl_size, 0x00FF0000);
			else if (arr[y][x] == '2')
				pxl_put(&img, x * pxl_size, y * pxl_size, 0x00FF00FF);
			x++;
		}
		y++;
		
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}