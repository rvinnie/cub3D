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
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	t_map s_map;

	
	if (argc != 2)
		put_error(&s_map, NULL, 1);
	s_map.mlx = mlx_init();
	main_parser(argv[1], &s_map);
	s_map.win = mlx_new_window(s_map.mlx, s_map.w, s_map.h, "cub3D");
	// print_arr(s_map.map);
	// valid_checker
	painter(&s_map);
	return (0);
}
