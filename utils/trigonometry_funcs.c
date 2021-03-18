/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigonometry_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 01:16:09 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/11 01:16:10 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	positive_sin(double deg)
{
	double	val;

	val = sin(deg);
	if (val < 0)
		val *= -1;
	return (val);
}

double	positive_tan(double deg)
{
	double	val;

	val = tan(deg);
	if (val < 0)
		val *= -1;
	return (val);
}

double	positive_cos(double deg)
{
	double	val;

	val = cos(deg);
	if (val < 0)
		val *= -1;
	return (val);
}
