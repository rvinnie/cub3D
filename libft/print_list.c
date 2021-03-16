#include "../includes/cub3d.h"

void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", *(char **)lst->content);
		lst = lst->next;
	}
}

void	print_arr2(int h, char **arr)
{
	int i = 0;

	while (h--)
		printf("%s\n", arr[i++]);
}