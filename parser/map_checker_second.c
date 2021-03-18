/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 19:44:21 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/17 19:44:23 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*make_cur_line(char *start_line, int arr_width)
{
	char	*line;
	int		i;
	int		len;

	if (!(line = (char *)ft_calloc(arr_width + 3, sizeof(char))))
		return (NULL);
	len = ft_strlen(start_line);
	i = 0;
	line[i++] = '9';
	while (arr_width--)
	{
		if (i > len)
			line[i] = '0';
		else
			line[i] = start_line[i - 1];
		i++;
	}
	line[i++] = '9';
	line[i] = '\0';
	return (line);
}

char	*make_void_line(int arr_width)
{
	char	*line;
	int		i;

	if (!(line = ft_calloc(arr_width + 3, sizeof(char))))
		return (NULL);
	arr_width += 2;
	i = 0;
	while (arr_width--)
		line[i++] = '9';
	line[i] = '\0';
	return (line);
}
