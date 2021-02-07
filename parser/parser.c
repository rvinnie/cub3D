#include "../includes/cub3D.h"

t_map_info lst_to_arr(t_list *head, t_map_info s_map_info)
{
	t_list			*cur;
	int				i;
	int				lst_size;

	cur = head;
	lst_size = ft_lstsize(cur);
	if(!(s_map_info.map = (char **)malloc((lst_size + 1) * sizeof(char *))))
		put_error(4);
	s_map_info.map_height = lst_size;
	//x, y player
	// s_map_info.s_player_info->x_pos = 40;
	// s_map_info.s_player_info->y_pos = 40;
	i = 0;
	while (cur)
	{
		s_map_info.map[i] = cur->content;
		cur = cur->next;
		i++;
	}
	return (s_map_info);
}


t_map_info parser(char *path, t_map_info s_map_info)
{
	int		fd;
	int		count;
	char	*line;
	t_list	*head;

	if ((fd = open(path, O_RDONLY)) == -1) //"/home/rvinnie/code/21school/projects/cub3D/parser/text.txt"
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
	s_map_info = lst_to_arr(head, s_map_info);
	close(fd);
	return (s_map_info);
}
