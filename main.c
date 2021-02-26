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

int main(int argc, char *argv[])
{
	// int 	i;

	t_map s_map;

	if (argc != 2)
		put_error(1);
	parser(argv[1], &s_map);
	// i = 0;
	// while (s_map.map_height--)
	// {
	// 	printf("%s\n", s_map.map[i]);
	// 	i++;
	// }

	painter(&s_map);
	return (0);
}
