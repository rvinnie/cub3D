#include "../includes/cub3d.h"


typedef struct
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_len;
	int		endian;
}			t_data;


// int     offset = (y * line_length + x * (bits_per_pixel / 8));

void pxl_put(t_data *data, int x, int y, int color, int size)
{
	char *dst;
	int i = 0;
	int j = 0;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			dst = data->addr + ((y + i) * data->line_len + (x + j) * (data->bit_per_pixel / 8));
			*(unsigned int*)dst = color;
			j++;
		}
		i++;
	}
}
