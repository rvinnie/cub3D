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

#include "../cub3d.h"

char	*create_new_line(char *line)
{
	int		len;
	int		i;
	char	*new_line;

	len = ft_strlen(line);
	if (!(new_line = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (len--)
	{
		if (line[i] == ' ')
			new_line[i] = '0';
		else
			new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	lst_to_arr(t_list *head, t_map *s_map)
{
	t_list			*cur;
	int				i;
	int				lst_size;
	char			*new_line;

	cur = head;
	lst_size = ft_lstsize(cur);
	if (!(s_map->map = (char **)ft_calloc((lst_size + 1), sizeof(char *))))
		put_error(s_map, NULL, 4, 1);
	s_map->map_height = lst_size;
	i = 0;
	while (cur)
	{
		new_line = create_new_line((char *)cur->content);
		if (!new_line)
			put_error(s_map, NULL, 4, 1);
		s_map->map[i] = new_line;
		cur = cur->next;
		i++;
	}
	s_map->map[i] = ft_strdup("\0");
}
