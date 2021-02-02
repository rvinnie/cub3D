#include "includes/cub3D.h"

int main(int argc, char *argv[])
{
	// int i = 0;
	t_map_info s_map_info;
	if (argc != 2)
		put_error(1);
	s_map_info = parser(argv[1], s_map_info);
	// while (s_map_info.map_height--)
	// {
	// 	printf("%s\n", s_map_info.map[i]);
	// 	i++;
	// }

	void    *mlx;

    mlx = mlx_init();
	return (0);
}