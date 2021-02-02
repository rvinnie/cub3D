#ifndef CUB3D_H
# define CUB3D_H
# include "../gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h> //open
# include <sys/types.h>
# include <sys/stat.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct
{
	char			**map;
	int				map_height;
}	t_map_info;

// Lst functions
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *cur);
int			ft_lstsize(t_list *lst);

// Utils functions
void		put_error(int flag);

// Parser functions
t_map_info parser(char *path, t_map_info s_map_info);
t_map_info lst_to_arr(t_list *head, t_map_info s_map_info);

// Testing functions
void		print_list(t_list *lst); // FOR TESTING
#endif