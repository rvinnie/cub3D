/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:43:35 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:43:37 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	print_arr(char **arr)
{
	int i;

	i = 0;
	while (i < 3)
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_map	s_map;
	int		screenshot;
	
	if (argc < 2 || argc > 3)
		put_error(&s_map, NULL, 1);
	s_map.mlx = mlx_init();
	if (argc == 3)
		screenshot = 1;
	else
		screenshot = 0;
	main_parser(argv[1], &s_map);
	map_checker(&s_map);
	s_map.win = mlx_new_window(s_map.mlx, s_map.w, s_map.h, "cub3D"); 
	// valid_checker
	if (screenshot)
		painter(&s_map, screenshot, argv[2]);
	else
		painter(&s_map, screenshot, NULL);
	exit_game(&s_map);
	return (0);
}
