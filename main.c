#include "fdf.h"

void		testdraw(void *mlx, void *win)
{
	int		x;
	int		y;

	x = 50;
	while (x++ < 200)
	{
		y = 50;
		while (y++ < 200)
			mlx_pixel_put(mlx, win, x, y, 0x009FE855);
	}
	x = 200;
	while (x++ < 350)
	{
		y = 200;
		while (y++ < 350)
			mlx_pixel_put(mlx, win, x, y, 0x0077B5FE);
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
