#include "fdf.h"

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
