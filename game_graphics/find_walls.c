/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:15:32 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/23 15:15:34 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub3d.h"
       
void	find_first_horisontal_wall(t_ray *s_ray, t_player *s_player)
{
	double first_h_x;
	double first_h_y;
	long int x_pos;
	long int y_pos;

	x_pos = s_player->x_pos;
	y_pos = s_player->y_pos;
	if (s_ray->alpha >= 0 && s_ray->alpha <= M_PI) // If the ray is facing up
		first_h_y = (int)(y_pos / PXL_SIZE) * PXL_SIZE - .00000000001; // A.y = rounded_down(Py/64) * (64) - 1
	else														 // If the ray is facing down
		first_h_y = (int)(y_pos / PXL_SIZE) * PXL_SIZE + PXL_SIZE;	// A.y = rounded_down(Py/64) * (64) + 64; 
	first_h_x = x_pos + (y_pos - first_h_y) / tan(s_ray->alpha);
	s_ray->cur_h_x = first_h_x;
	s_ray->cur_h_y = first_h_y;
	// printf("%ld\n", s_ray->cur_h_y);
	
}

void	find_horisontal_wall(t_ray *s_ray, t_map *s_map)
{
	double     	y_dist;
	double     	x_dist;
	long int  	is_wall_x;
	long int  	is_wall_y;

	find_first_horisontal_wall(s_ray, &(s_map->s_player)); // 1) Find coordinate of the first intersection (point A in this example).
	// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00FF00FF, 4);
	while (INFINITY_LOOP)
	{

		is_wall_x = s_ray->cur_h_x / PXL_SIZE;
		is_wall_y = s_ray->cur_h_y / PXL_SIZE;
		check_border(s_map, &is_wall_y, &is_wall_x);
		if (s_map->map[is_wall_y][is_wall_x] == '1') // 4) Check the grid at the intersection point. If there is a wall on the grid, stop and calculate the distance.
			break;
		y_dist = PXL_SIZE;
		if (s_ray->alpha >= 0 && s_ray->alpha <= M_PI)                 // 2) Find Ya. (Note: Ya is just the height of the grid; however, if the ray is facing up, Ya will be negative, if the ray is facing down, Ya will bepositive.)
			y_dist = -PXL_SIZE;
		x_dist = PXL_SIZE / positive_tan(s_ray->alpha);                          // 3) Find Xa. Xa = 64/tan(a)
		if (s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2)
			x_dist *= -1;
		s_ray->cur_h_x += x_dist;  // 5) If there is no wall, extend the to the next intersection point. Notice that the coordinate of the next intersection point -call it (Xnew,Ynew) is Xnew=Xold+Xa, and Ynew=YOld+Ya.
		s_ray->cur_h_y += y_dist;
		// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00000000, 1);
	}
	// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00000000, 1);
	if (s_ray->cur_h_x < 0)
		s_ray->cur_h_x = 0;
	if (s_ray->cur_h_y < 0)
		s_ray->cur_h_y = 0;

	// s_ray->hor_dist = fabs(s_map->s_player.x_pos - s_ray->cur_h_x) / positive_cos(s_ray->alpha);
	s_ray->hor_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2) + pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	// s_ray->hor_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2) + pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	// s_ray->hor_dist = fabs(s_map->s_player.y_pos - s_ray->cur_h_y) / positive_sin(s_ray->alpha);
	// s_ray->hor_dist = fabs(s_map->s_player.x_pos - s_ray->cur_h_x) / positive_cos(s_ray->alpha);
	// s_ray->hor_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2) + pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	if (s_ray->cur_h_x > 10000 || s_ray->cur_h_y > 10000)
		s_ray->hor_dist = 10000;
	s_ray->hor_wall_x = s_ray->cur_h_x;
	s_ray->hor_wall_y = s_ray->cur_h_y;
    // calculate distance
}

void	find_first_vertical_wall(t_ray *s_ray, t_player *s_player)
{
        //  Finding the coordinate of A.  
    //    If the ray is facing up      
    //      A.y = rounded_down(Py/64) * (64) - 1;
    //    If the ray is facing down
    //      A.y = rounded_down(Py/64) * (64) + 64;
	double first_h_x;
	double first_h_y;
	long int x_pos;
	long int y_pos;

	x_pos = s_player->x_pos;
	y_pos = s_player->y_pos;
	if (s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2)
		first_h_x = (int)(x_pos / PXL_SIZE) * PXL_SIZE - .00000000001; //A.y = Py + (Px-A.x)*tan(ALPHA);
	else
		first_h_x = (int)(x_pos / PXL_SIZE) * PXL_SIZE + PXL_SIZE;
	first_h_y = y_pos + (x_pos - first_h_x) * tan(s_ray->alpha);
	s_ray->cur_h_x = first_h_x;
	s_ray->cur_h_y = first_h_y;
	
}

void	find_vertical_wall(t_ray *s_ray, t_map *s_map)
{
	double         	y_dist;
	double         	x_dist;
	long int		is_wall_x;
	long int		is_wall_y;

	find_first_vertical_wall(s_ray, &(s_map->s_player)); // 1) Find coordinate of the first intersection (point A in this example).
	// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00000000, 4);
	while (INFINITY_LOOP)
	{
		is_wall_x = s_ray->cur_h_x / PXL_SIZE;
		is_wall_y = s_ray->cur_h_y / PXL_SIZE;
		x_dist = (PXL_SIZE);
		if (s_ray->alpha >= M_PI / 2 && s_ray->alpha <= 3 * M_PI / 2)                 // 2) Find Ya. (Note: Ya is just the height of the grid; however, if the ray is facing up, Ya will be negative, if the ray is facing down, Ya will bepositive.)
			x_dist = -(PXL_SIZE);
		y_dist = (PXL_SIZE) * positive_tan(s_ray->alpha);                        // 3) Find Xa. Xa = 64/tan(a)
		if (s_ray->alpha >= 0 && s_ray->alpha <= M_PI)
			y_dist *= -1;
		check_border(s_map, &is_wall_y, &is_wall_x);
		if (s_map->map[is_wall_y][is_wall_x] == '1')
			break;
		s_ray->cur_h_x += x_dist;  // 5) If there is no wall, extend the to the next intersection point. Notice that the coordinate of the next intersection point -call it (Xnew,Ynew) is Xnew=Xold+Xa, and Ynew=YOld+Ya.
		s_ray->cur_h_y += y_dist;
		// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00000000, 1);
	}
	// pxl_put(&s_map->s_img, (int)s_ray->cur_h_x, (int)s_ray->cur_h_y, 0x00000000, 1);
	if (s_ray->cur_h_x < 0)
		s_ray->cur_h_x = 0;
	if (s_ray->cur_h_y < 0)
		s_ray->cur_h_y = 0;
	// s_ray->ver_dist = fabs(s_map->s_player.y_pos - s_ray->cur_h_y) / positive_sin(s_ray->alpha);
	s_ray->ver_dist = sqrt((pow(s_map->s_player.x_pos - s_ray->cur_h_x, 2) + pow(s_map->s_player.y_pos - s_ray->cur_h_y, 2)));
	// s_ray->ver_dist = (fabs(s_map->s_player.x_pos - s_ray->cur_h_x) / positive_cos(s_ray->alpha));
	// s_ray->hor_dist = fabs(s_map->s_player.y_pos - s_ray->cur_h_y) / positive_sin(s_ray->alpha);
	if (s_ray->cur_h_x > 100000 || s_ray->cur_h_y > 100000)
		s_ray->ver_dist = 100000;
	s_ray->ver_wall_x = s_ray->cur_h_x;
	s_ray->ver_wall_y = s_ray->cur_h_y;
    // calculate distance
}
