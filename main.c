/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/11 15:38:06 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			gomlx(void)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "fdf");
	testdraw(mlx, win);
	mlx_loop(mlx);
}

int			main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl("usage: <filename> | name of fdf file");
		return (0);
	}
	ft_putendl(av[1]);
	//gomlx();
	return (0);
}
