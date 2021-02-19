#include "../includes/cub3d.h"

double	fishbowl_handler(double alpha)
{
	double	dir_alpha = alpha;
	if (alpha >= M_PI / 4 && alpha <= M_PI * 3 / 4)
		dir_alpha = fabs(M_PI / 2 - alpha);
	else if (alpha > M_PI * 3 / 4 && alpha < M_PI * 5 / 4)
		dir_alpha = fabs(M_PI - alpha);
	else if (alpha >= M_PI * 5 / 4 && alpha <= M_PI * 7 / 4)
		dir_alpha = fabs(M_PI * 3 / 2 - alpha);
	// else if (alpha > M_PI * 7 / 4 && alpha <= M_PI * 2)
	// 	dir_alpha = fabs(M_PI * 2 - alpha);
	// while (fabs(M_PI / 2 - dir_alpha) > 0.00001)
	// 	dir_alpha -= M_PI / 2;
	return (positive_cos(dir_alpha));
}