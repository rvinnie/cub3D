/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_to_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:17:23 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/09 13:17:24 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	dir_to_degree(t_player s_player)
{
	char	dir;
	double	alpha;

	dir = s_player.direction;
	if (dir == 'N')
		alpha = M_PI / 2;
	else if (dir == 'S')
		alpha = M_PI * 3 / 2;
	else if (dir == 'W')
		alpha = M_PI;
	else
		alpha = 0;
	return (alpha);
}
