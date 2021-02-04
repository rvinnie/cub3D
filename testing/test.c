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

	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			dst = data->addr + ((y + i) * data->line_len + (x + j) * (data->bit_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}

int main()
{
	void *mlx;
	int x = 0;
	int y = 0;
	int i = 5;
	void *win;
	t_data img;


	// int arr[5][5] = {
	// 	{1,1,1,1,1},
	// 	{1,1,1,1,1},
	// 	{1,1,1,0,1},
	// 	{1,0,1,1,1},
	// 	{1,1,1,1,1},
	// 	};

	char arr[5][5] = {
		"11111",
		"11111",
		"11101",
		"10111",
		"11111",
	};
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "Hello!");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_len, &img.endian);

	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (arr[y][x] == 49)
				pxl_put(&img, x * i, y * i, 0x00FF0000);
			x++;
		}
		y++;
		
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
}