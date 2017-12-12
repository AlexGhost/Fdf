/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:53:20 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 16:37:42 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	createwindow(int **tab, int x, int y)
{
	void		*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "fdf");
	mlx_loop(mlx);
}

void		fdf_displayfile(int **tab, int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putnbr(tab[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	//createwindow(tab, x, y);
}
