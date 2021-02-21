#include "../includes/cub3d.h"

void	forward_step(double alpha, long int *x_pos, long int *y_pos)
{
	*x_pos += PLAYER_STEP * positive_cos(alpha + M_PI / 6);
	*y_pos += PLAYER_STEP * positive_sin(alpha + M_PI / 6);
}

void	backward_step(double alpha, long int *x_pos, long int *y_pos)
{
	*x_pos -= PLAYER_STEP * positive_cos(alpha);
	*y_pos -= PLAYER_STEP * positive_sin(alpha);
}