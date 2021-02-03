#include "../includes/cub3D.h"

int main()
{
	void *mlx;
	void *window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 600, 600, "Testing");
	mlx_loop(mlx);
}