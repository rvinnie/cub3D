/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 17:38:18 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/11 17:38:19 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	change_degree(double degree, double count, int direction)
{
	if (direction > 0)
		degree += count;
	else
		degree -= count;
	if (degree >= 2 * M_PI)
		degree -= 2 * M_PI;
	else if (degree < 0)
		degree += 2 * M_PI;
	return (degree);
}
