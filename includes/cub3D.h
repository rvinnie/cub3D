#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h> //
# include <string.h>
# include <unistd.h>
# include <fcntl.h> //open
# include <sys/types.h>
# include <sys/stat.h>

# define WALL_COLOR 0x005498BA
# define FLOOR_COLOR 0x00FFFFFF
# define PLAYER_COLOR 0x00FF0DD3
# define SPRITE_COLOR 0x002CA838

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}			t_address;

typedef struct
{
	char			**map;
	int				map_height;
	void			*mlx;
	void			*win;
}	t_map_info;

// Libft functions
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *cur);
int			ft_lstsize(t_list *lst);
size_t		ft_strlen(const char *s);

// Utils functions
void		put_error(int flag);

// Parser functions
t_map_info	parser(char *path, t_map_info s_map_info);
t_map_info	lst_to_arr(t_list *head, t_map_info s_map_info);

// Painter functions
void		painter(t_map_info *s_map_info);
void		make_map_image(t_map_info *s_map_info)

// Testing functions
void		print_list(t_list *lst); // FOR TESTING
#endif