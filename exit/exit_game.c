#include "../includes/cub3d.h"

void	free_parser_info(t_text	**s_text)
{
	int i;

	i = 0;
	while (i < 4)
		free(s_text[i++]);
	free(s_text);
}

int		exit_game(t_map *s_map)
{

	mlx_destroy_image(s_map->mlx, s_map->s_img.img);
	mlx_destroy_window(s_map->mlx, s_map->win);
	free_parser_info(s_map->s_text);
	exit(1);
}