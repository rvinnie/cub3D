/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:44:19 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:44:20 by rvinnie          ###   ########.fr       */
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
	if(!(s_map->map = (char **)malloc((lst_size + 1) * sizeof(char *))))
		put_error(4);
	s_map->map_height = lst_size;
	i = 0;
	while (cur)
	{
		s_map->map[i] = cur->content;
		cur = cur->next;
		i++;
	}
}

void	create_player(t_map *s_map, int x, int y, char dir)
{
	s_map->s_player.x_pos = x * PXL_SIZE;
	s_map->s_player.y_pos = y * PXL_SIZE;
	s_map->s_player.direction = dir;
}

void	find_player(t_map *s_map)
{
	int		i;
	int		j;
	int		is_correct;
	char	let;

	i = 0;
	is_correct = 0;
	while (i < s_map->map_height)
	{
		j = 0;
		while (s_map->map[i][j])
		{
			let = s_map->map[i][j];
			if (find_chr(let, "NSWE"))
			{
				is_correct = 1;
				create_player(s_map, j, i, let);
				break;
			}
			j++;
		}
		i++;
	}
	if (!is_correct)
		put_error(5);
}

void	parser(char *path, t_map *s_map)
{
	int		fd;
	int		count;
	char	*line;
	t_list	*head;
	
	// path = "/Users/rvinnie/Desktop/cub3d/testing/text.txt";
	if ((fd = open(path, O_RDONLY)) == -1)
		put_error(2);
	head = NULL;
	line = NULL;
	while ((count = get_next_line(fd, &line)))
	{
		if (count == -1)
			put_error(3);
		ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	lst_to_arr(head, s_map);
	find_player(s_map);
	close(fd);
}
