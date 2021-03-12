#include "../includes/cub3d.h"

void	create_sprite(t_map *s_map, t_spr **arr_spr, int x, int y, int count)
{
	t_spr *cur_spr;

	if (!(cur_spr = ft_calloc(1, sizeof(t_spr *))))
		put_error(s_map, NULL, 4);
	cur_spr->x_pos = x;
	cur_spr->y_pos = y;
	arr_spr[count] = cur_spr;
}

void	find_sprites(t_map *s_map)
{
	int		i;
	int		j;
	int		count;
	char	let;
	t_spr	**arr_spr;

	i = 0;
	count = 0;
	arr_spr = (t_spr **)ft_calloc(s_map->count_spr, sizeof(t_spr *));
	while (i < s_map->map_height)
	{
		j = 0;
		while (s_map->map[i][j])
		{
			let = s_map->map[i][j];
			if (let == '2')
			{
				create_sprite(s_map, arr_spr, j, i, count);
				count++;
			}
			j++;
		}
		i++;
	}
	s_map->s_spr = arr_spr;
}