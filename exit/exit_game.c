/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:48:22 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/17 16:48:24 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_sprites(t_spr **s_spr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(s_spr[i++]);
}

void	free_parser_info(t_text **s_text)
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

int		exit_game(t_map *s_map, int stage)
{
	if (stage >= 1)
		free_paths(s_map);
	if (stage >= 2)
		free_parser_info(s_map->s_text);
	if (stage >= 3)
		free_sprites(s_map->s_spr, s_map->count_spr);
	if (stage >= 4)
		free(s_map->s_spr_info);
	if (stage >= 5)
		free_hidden_arr(s_map->map, s_map->map_height);
	if (stage >= 6)
	{
		mlx_destroy_image(s_map->mlx, s_map->s_img.img);
		mlx_destroy_window(s_map->mlx, s_map->win);
	}
	exit(1);
}
