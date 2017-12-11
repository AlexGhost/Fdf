#include "fdf.h"
#include "fdf_colors.h"

void		testdraw(void *mlx, void *win)
{
	int		x;
	int		y;

	x = 50;
	while (x++ < 200)
	{
		y = 50;
		while (y++ < 200)
			mlx_pixel_put(mlx, win, x, y, C_GREEN);
	}
	x = 200;
	while (x++ < 350)
	{
		y = 50;
		while (y++ < 200)
			mlx_pixel_put(mlx, win, x, y, C_GREEN);
	}
	x = 200;
	while (x++ < 350)
	{
		y = 200;
		while (y++ < 350)
			mlx_pixel_put(mlx, win, x, y, C_BLUE);
	}
	x = 150;
	while (x++ < 250)
	{
		y = 150;
		while (y++ < 250)
			mlx_pixel_put(mlx, win, x, y, C_WHITE);
	}
}

int			main(void)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "fdf");
	testdraw(mlx, win);
	mlx_loop(mlx);
	return (0);
}
