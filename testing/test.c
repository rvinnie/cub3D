#include "../includes/cub3d.h"



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

int main()
{
	// void *img;
	// char *filename = "/Users/rvinnie/Desktop/cub3d/textures/cat.xpm";
	// void *mlx_ptr = mlx_init();
	// img = mlx_xpm_file_to_image(mlx_ptr, filename, 0, 0);
	// void *win = mlx_new_window(mlx_ptr, 1000, 1000, "cub3D");
	// mlx_loop(mlx_ptr);



	void    *mlx;
	t_img 	s_img;
	char	*filename = "/Users/rvinnie/Desktop/cub3d/textures/cat.xpm";
    void    *mlx_win;
	void 	*img;
	int a;
	int b;
	int c = 0;
	int h = 0;
	int x;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	s_img.img = mlx_xpm_file_to_image(mlx, filename, &a, &b);
	// printf("%d\n", a);
	s_img.addr = mlx_get_data_addr(s_img.img, &s_img.bit_per_pixel, &s_img.line_len, &s_img.endian);

	// printf("%s\n", ((char *)s_img.addr));
	x = 1;
	printf("%x\n", *((unsigned *)s_img.addr + a * 2));
	// c = 0;
	// while (c < 661)
	// {
	// 	pxl_put(&s_img, 100, c, *((unsigned int*)(s_img.addr) + c * 640 + 100), 1);
	// 	c++;
	// }
	// c = 0;
	// while (c < 661)
	// {
	// 	h =0;
	// 	// if (c == 100)
	// 	// 	continue;
	// 	while (h < 640)
	// 	{
	// 		pxl_put(&s_img, h, c, 0x00000000, 1);
	// 		h++;
	// 	}
	// 	c++;
		
	// }
	// c = 0;
	// while (c < 661)
	// {
	// 	pxl_put(&s_img, 100, c, *((unsigned int*)(s_img.addr) + c + 100), 1);
	// 	c++;
	// }
	// c = 0;
	mlx_put_image_to_window(mlx, mlx_win, s_img.img, 0, 0);
    mlx_loop(mlx);
}