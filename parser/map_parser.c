/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:12:07 by rvinnie           #+#    #+#             */
/*   Updated: 2021/03/11 12:12:11 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>

int		is_line_checker(char *str)
{
	char	*valid_sym;
	size_t	i;
	int		j;
	int		flag;
	int		second_len;

	valid_sym = "012NSWE ";
	second_len = ft_strlen(valid_sym);
	i = 0;
	while (i < ft_strlen(str))
	{
		j = 0;
		flag = 0;
		while (j < second_len)
		{
			if (str[i] == valid_sym[j++])
				flag = 1;
		}
		if (flag != 1)
			return (0);
		i++;
	}
	return (1);
}

int		is_map_checker(char **str_arr)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (str_arr[i])
		res = is_line_checker(str_arr[i++]);
	return (res);
}

int		check_spaces(t_map *s_map, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	put_error(s_map, NULL, 5, 1);
	return (0);
}

char	*skip_first(int fd, t_map *s_map)
{
	int		count;
	char	*line;
	char	*tmp;

	line = NULL;
	while ((count = get_next_line(fd, &line)))
	{
		tmp = line;
		if (count == -1)
			put_error(s_map, NULL, 3, 1);
		if (!line[0])
		{
			free(tmp);
			continue ;
		}
		if (is_line_checker(line) == 1)
			break ;
		else
			free(line);
		line = NULL;
	}
	return (line);
}

void	get_map(t_map *s_map, int fd)
{
	int		count;
	char	*line;
	t_list	*head;
	int		len;

	head = NULL;
	s_map->map_width = 0;
	line = skip_first(fd, s_map);
	ft_lstadd_back(&head, ft_lstnew(line));
	while ((count = get_next_line(fd, &line)))
	{
		if (count == -1)
			put_error(s_map, NULL, 3, 1);
		if (check_spaces(s_map, line) == 0)
			continue ;
		len = ft_strlen(line);
		if (len > s_map->map_width)
			s_map->map_width = len;
		ft_lstadd_back(&head, ft_lstnew(line));
		line = NULL;
	}
	if (check_spaces(s_map, line) != 0)
		ft_lstadd_back(&head, ft_lstnew(line));
	lst_to_arr(head, s_map);
	ft_lstclear(&head);
}
