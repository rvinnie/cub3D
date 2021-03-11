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
# include "libft.h"
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
	int				width;
	int				height;
	char			*addr;
	// t_img			s_img;
}					t_text;

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
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sprite;
	unsigned long	floor_c;
	unsigned long	ceil_c;
}					t_parser;

typedef struct
{
	int				map_width;
	int				map_height;
	int				w;
	int				h;
	char			**map;
	void			*mlx;
	void			*win;
	t_img			s_img;
	t_text			**s_text;
	t_text			cur_text;
	t_ray			*s_ray;
	t_player		s_player;
	t_parser		*s_parser;
}					t_map;

// Libft functions
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *cur);
int					ft_lstsize(t_list *lst);
int					find_chr(char ch, char *str);

// Utils functions
void				put_error(t_map *s_map, char **arr, int flag);
double				dir_to_degree(t_player s_player);
unsigned long		rgb_to_hex(t_map *s_map, char *rgb);
void				lst_to_arr(t_list *head, t_map *s_map);
double				positive_sin(double deg);
double				positive_cos(double deg);
double				positive_tan(double deg);
void				check_border(t_map *s_map, int *y, int *x);
void				free_arr(char **arr);

// Moving
double				change_degree(double degree, double count, int direction);
void				make_step(t_map *s_map, double *x_pos, double *y_pos, char side);

//Map valid
int					is_map_checker(t_map *s_map, char **str_arr);

// Parser functions
void				main_parser(char *path, t_map *s_map);
void				get_map(t_map *s_map, int fd);
void				lst_to_arr(t_list *head, t_map *s_map);
void				find_player(t_map *s_map);
t_text				**get_texture(t_map *s_map);
void				choose_info(t_map *s_map, char **info_arr);
void				check_path(char *path, t_map *s_map);
void				map_checker(t_map *s_map);

// Painter functions
void				pxl_put(t_img *data, int x, int y, int color, int pxl_size);
void				painter(t_map *s_map);
void				main_drawer(t_map *s_map);

// Raycaster functions
void				raycasting(t_map *s_map, t_ray *s_ray);
void				draw_line(t_ray *s_ray, t_map *s_map, double a);
void				find_first_horisontal_wall(t_ray *s_ray, t_player *s_player);
void				find_horisontal_wall(t_ray *s_ray, t_map *s_map);
void				find_first_vertical_wall(t_ray *s_ray, t_player *s_player);
void				find_vertical_wall(t_ray *s_ray, t_map *s_map);

// Textures functions
void				texture_slice(t_map *s_map, int slice_height, int slice_x, double side_dist);

// Testing functions
void				print_list(t_list *lst); // FOR TESTING
void				testing_raycasting(t_map *s_map);
#endif
