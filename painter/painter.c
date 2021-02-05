#include "../includes/cub3D.h"

void painter(t_map_info *s_map_info)
{
	s_map_info->mlx = mlx_init();
	s_map_info->win = mlx_new_window(s_map_info->mlx, 500, 500, "Hello!");
	make_map_image(s_map_info);
	mlx_loop(s_map_info->mlx);
}
