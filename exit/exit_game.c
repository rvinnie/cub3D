#include "../includes/cub3d.h"

void	free_parser_info(t_text	**s_text)
{
	int i;

	i = 0;
	while (i < 4)
		free(s_text[i++]);
	free(s_text);
}

void	free_paths(t_map *s_map)
{
	free(s_map->s_parser->no);
	free(s_map->s_parser->so);
	free(s_map->s_parser->we);
	free(s_map->s_parser->ea);
	free(s_map->s_parser->sprite);
	free(s_map->s_parser);
}

int		exit_game(t_map *s_map)
{

	mlx_destroy_image(s_map->mlx, s_map->s_img.img);
	mlx_destroy_window(s_map->mlx, s_map->win);
	free_hidden_arr(s_map->map, s_map->map_height);
	free_parser_info(s_map->s_text);
	free_paths(s_map);
	// float x;
	// scanf("%f", &x);
	exit(1);
}