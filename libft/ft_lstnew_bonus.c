#include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list *ft_lstnew(void *content)
{
	t_list *item;
	if (!(item = malloc(sizeof(t_list))))
		return (NULL);
	item->content = content;
	item->next = NULL;
}