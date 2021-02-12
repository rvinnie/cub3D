/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:43:21 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:43:22 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	if (!(item = malloc(sizeof(t_list))))
		return (NULL);
	item->content = content;
	item->next = NULL;
	return (item);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	else
		return (NULL);
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *cur)
{
	t_list	*tail;

	tail = *lst;
	if (*lst)
	{
		tail = ft_lstlast(*lst);
		tail->next = cur;
	}
	else
		*lst = cur;
}

int		ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// FOR TESTING

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

// int main()
// {
// 	// int f = 123;
// 	char *line = "qwer";
// 	// char *x;
// 	t_list *head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(line));
// 	// x = head->content;
// 	// printf("%s\n", (char*)head->content);
// 	print_list(head);
// }
