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

# include "libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define PLAYER_STEP 10
# define PXL_SIZE 64
# define INFINITY_LOOP 1

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct
{
	double				x_pos;
	double				y_pos;
	char				direction;
}						t_player;

typedef struct
{
	int					width;
	int					height;
	char				*addr;
}						t_text;

typedef struct
{
	int					bit_per_pixel;
	int					line_len;
	int					endian;
	void				*img;
	char				*addr;
}						t_img;

typedef struct
{
	double				x_pos;
	double				y_pos;
	double				dist;
	double				spr_dir;
	double				h_off;
	double				v_off;
	double				x_step;
	double				y_step;
	double				spr_size;
	double				i;
	double				j;
}						t_spr;

typedef struct
{
	double				ray_dir_x;
	double				ray_dir_y;
	double				cur_h_x;
	double				cur_h_y;
	double				ver_wall_x;
	double				ver_wall_y;
	double				ver_dist;
	double				hor_wall_x;
	double				hor_wall_y;
	double				hor_dist;
	double				alpha;
	double				fov_angle;
}						t_ray;

typedef struct
{
	long				floor_c;
	long				ceil_c;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*sprite;
}						t_parser;

typedef struct
{
	int					map_width;
	int					map_height;
	int					w;
	int					h;
	char				**map;
	void				*mlx;
	void				*win;
	t_img				s_img;
	t_text				**s_text;
	t_text				cur_text;
	t_spr				**s_spr;
	t_text				*s_spr_info;
	int					count_spr;
	t_ray				*s_ray;
	t_player			s_player;
	t_parser			*s_parser;
}						t_map;

t_list					*ft_lstnew(void *content);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *cur);
int						ft_lstsize(t_list *lst);
void					ft_lstclear(t_list **lst);
int						find_chr(char ch, char *str);
// void					mlx_get_screen_size(int *width, int *height);
void					put_error(t_map *s_map, char **arr,
									int flag, int stage);
double					dir_to_degree(t_player s_player);
unsigned long			rgb_to_hex(t_map *s_map, char *rgb);
void					lst_to_arr(t_list *head, t_map *s_map);
int						arr_len(char **info_arr);
int						is_line_nbr(char *line);
double					positive_sin(double deg);
double					positive_cos(double deg);
double					positive_tan(double deg);
void					check_border(t_map *s_map, int *y, int *x);
void					sort_sprites(t_map *s_map, int size);
void					free_hidden_arr(char **arr, int y);
void					free_arr(char **arr);
int						exit_game(t_map *s_map, int stage);
double					change_degree(double degree, double count,
													int direction);
void					make_step(t_map *s_map, double *x_pos,
								double *y_pos, char side);
int						is_map_checker(char **str_arr);
int						check_third_arg(char *third_arg);
void					check_path(char *path, t_map *s_map);
void					map_checker(t_map *s_map);
void					main_parser(char *path, t_map *s_map);
void					get_map(t_map *s_map, int fd);
void					lst_to_arr(t_list *head, t_map *s_map);
void					find_player(t_map *s_map);
void					find_sprites(t_map *s_map);
int						find_count_spr(char **map, int map_height);
t_text					**get_texture(t_map *s_map);
t_text					*get_sprite(t_map *s_map, char *filename);
void					choose_info(t_map *s_map, char **info_arr);
void					pxl_put(t_img *data, int x, int y, int color);
void					painter(t_map *s_map, int screenshot, char *third_arg);
void					main_drawer(t_map *s_map, int screenshot);
void					make_screenshot(t_map *s_map, t_img s_img);
void					raycasting(t_map *s_map, t_ray *s_ray);
void					draw_line(t_ray *s_ray, t_map *s_map, double a);
void					find_first_horisontal_wall(t_ray *s_ray,
											t_player *s_player);
void					find_horisontal_wall(t_ray *s_ray, t_map *s_map);
void					find_first_vertical_wall(t_ray *s_ray,
													t_player *s_player);
void					find_vertical_wall(t_ray *s_ray, t_map *s_map);
void					sprite_handler(t_map *s_map, double *dists);
char					*make_void_line(int arr_width);
char					*make_cur_line(char *start_line, int arr_width);
void					texture_slice(t_map *s_map, int slice_height,
									int slice_x, double side_dist);
t_text					choose_texture(t_map *s_map);
#endif
