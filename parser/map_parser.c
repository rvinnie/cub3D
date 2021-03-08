#include "../includes/cub3d.h"

int		is_line_checker(char *str)
{
	char	*valid_sym;
	int		i;
	int		j;
	int		flag;
	int		first_len;
	int		second_len;

	if (!(valid_sym = ft_strdup("01 2NSWE")))
		return (-1);
	first_len = ft_strlen(str);
	second_len = ft_strlen(valid_sym);
	i = 0;
	while (i < first_len)
	{	
		j = 0;
		flag = 0;
		while (j < second_len)
		{
			if (str[i] == valid_sym[j])
				flag = 1;
			j++;
		}
		if (flag != 1)
			return (0);
		i++;
	}
	free(valid_sym);
	return (1);
}

int		is_map_checker(t_map *s_map, char **str_arr)
{
	int 	i;
	int		res;

	i = 0;
	res = 0;
	while (str_arr[i] && res == 0)
		res = is_line_checker(str_arr[i++]);
	if (res == -1)
		put_error(s_map, str_arr, 4);
	return (res);
}

int check_spaces(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
void	get_map(t_map *s_map, int fd)
{	
	int		count;
	char	*line;
	t_list	*head;

	head = NULL;
	line = NULL;
	while ((count = get_next_line(fd, &line)))
	{
		if (is_line_checker(line) != 1 || check_spaces(line) == 0)
			continue ;
		if (count == -1)
			put_error(s_map, NULL, 3);
		ft_lstadd_back(&head, ft_lstnew(line));
		line = NULL;
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	lst_to_arr(head, s_map);  //don't forget free list
}