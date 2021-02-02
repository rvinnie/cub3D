void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tail;

	tail = *lst;
	if (*lst)
	{
		tail = ft_lstlast(*lst);
		tail->next = new;
	}
	else
		*lst = new;
}