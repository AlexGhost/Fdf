#include "fdf.h"
#include "fdf_colors.h"

void		fdf_drawcube(void *mlx, void *win, int coord[], int color)
{
	int x;
	int y;

	x = coord[0];
	while (x <= coord[2])
	{
		y = coord[1];
		while (y <= coord[3])
		{
			mlx_pixel_put(mlx, win, x, y, color);
			y++;
		}
		x++;
	}
}

void		testdraw(void *mlx, void *win)
{
	int coord[4];

	coord[0] = 50;
	coord[1] = 50;
	coord[2] = 200;
	coord[3] = 200;
	fdf_drawcube(mlx, win, coord, C_GREEN);
	coord[0] = 200;
	coord[1] = 200;
	coord[2] = 350;
	coord[3] = 350;
	fdf_drawcube(mlx, win, coord, C_BLUE);
	coord[0] = 150;
	coord[1] = 150;
	coord[2] = 250;
	coord[3] = 250;
	fdf_drawcube(mlx, win, coord, C_WHITE);
}
