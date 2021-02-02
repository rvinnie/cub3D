void print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", *(char **)lst->content);
		lst = lst->next;
	}
}