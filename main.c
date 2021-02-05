#include "includes/cub3D.h"

int main(int argc, char *argv[])
{
	// int 	i;

	t_map_info s_map_info;
	if (argc != 2)
		put_error(1);
	s_map_info = parser(argv[1], s_map_info);
	// i = 0;
	// while (s_map_info.map_height--)
	// {
	// 	printf("%s\n", s_map_info.map[i]);
	// 	i++;
	// }

	painter(&s_map_info);
	return (0);
}