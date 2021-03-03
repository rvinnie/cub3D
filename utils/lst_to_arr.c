/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:05 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/02 16:49:06 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	lst_to_arr(t_list *head, t_map *s_map)
{
	t_list			*cur;
	int				i;
	int				lst_size;

	cur = head;
	lst_size = ft_lstsize(cur);
	if (!(s_map->map = (char **)malloc((lst_size + 1) * sizeof(char *))))
		put_error(s_map, NULL, 4);
	s_map->map_height = lst_size;
	i = 0;
	while (cur)
	{
		s_map->map[i] = cur->content;
		cur = cur->next;
		i++;
	}
}
