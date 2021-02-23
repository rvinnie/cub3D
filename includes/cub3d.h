/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:40:48 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:40:50 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h> //
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h> //open
# include <sys/types.h>
# include <sys/stat.h>

# define WALL_COLOR 0x005498BA
# define FLOOR_COLOR 0x00FFFFFF
# define PLAYER_COLOR 0x00FF0DD3
# define SPRITE_COLOR 0x002CA838
# define SCREEN_WIDTH 320 * 2// 320
# define SCREEN_HEIGHT 200 * 2// 200
# define PLAYER_STEP 20 // 10
# define PXL_SIZE 64 // 64
# define PLAYER_SIZE 1 // 1
# define INFINITY_LOOP 1

// 320x200

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct
{
	void			*img;
	char			*addr;
	int				bit_per_pixel;
	int				line_len;
	int				endian;
}					t_img;

typedef struct
{
	double			x_pos;
	double			y_pos;
	char			direction;
}					t_player;

typedef struct
{
	double			ray_dir_x;
	double			ray_dir_y;
	double			cur_h_x;
    double			cur_h_y;
	double			ver_wall_x;
	double			ver_wall_y;
	double			ver_dist;
	double			hor_wall_x;
	double			hor_wall_y;
	double			hor_dist;
	double			alpha;
	double			fov_angle;
}					t_ray;

typedef struct
{
	char			**map;
	int				map_height;
	void			*mlx;
	void			*win;
	t_img			s_img;
	t_ray			*s_ray;
	t_player		s_player;
}					t_map;

// Libft functions
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *cur);
int					ft_lstsize(t_list *lst);
size_t				ft_strlen(const char *s);
int					find_chr(char ch, char *str);

// Utils functions
void				put_error(int flag);
double				dir_to_degree(t_player s_player);
double				positive_sin(double deg);
double				positive_cos(double deg);
double				positive_tan(double deg);
void				check_border(t_map *s_map, long int *y, long int *x);


// Moving
double				change_degree(double degree, double count, int direction);
void				make_step(t_map *s_map, double *x_pos, double *y_pos, int side);

// Parser functions
void				parser(char *path, t_map *s_map);
void				lst_to_arr(t_list *head, t_map *s_map);

// Painter functions
void				pxl_put(t_img *data, int x, int y, int color, int pxl_size);
void				painter(t_map *s_map);
void				make_map_image(t_map *s_map);

// Raycaster functions
void				raycasting(t_map *s_map, t_ray *s_ray);
void				draw_line(t_ray *s_ray, t_map *s_map, double a);
void				find_first_horisontal_wall(t_ray *s_ray, t_player *s_player);
void				find_horisontal_wall(t_ray *s_ray, t_map *s_map);
void				find_first_vertical_wall(t_ray *s_ray, t_player *s_player);
void				find_vertical_wall(t_ray *s_ray, t_map *s_map);

// Testing functions
void				print_list(t_list *lst); // FOR TESTING
void				testing_raycasting(t_map *s_map);
#endif
