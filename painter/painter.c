#include "../includes/cub3D.h"

void painter(t_map_info s_map_info)
{
	void *mlx;
	void *mlx_win;
	void *img;


	//
	printf("%d\n", s_map_info.map_height);
	//

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 600, 600, "Hello!!!");
	img = mlx_new_image(mlx, 600, 600);

	//
	printf ("%p", img);
	printf ("%p", mlx_win);
	//

	mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    mlx_loop(mlx);
}
