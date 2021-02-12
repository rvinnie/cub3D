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

#include "../includes/cub3d.h"

double	change_degree(double degree, int direction)
{
	if (direction > 0)
		degree += M_PI / 90;
	else
		degree -= M_PI / 90;
	if (degree >= 2 * M_PI)
		degree -= 2 * M_PI;
	else if (degree < 0)
		degree += 2 * M_PI;
	return (degree);
}
