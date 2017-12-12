/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:53:20 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 20:27:36 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

static void	deletemat(int **tab, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	createwindow(int **tab, int x, int y)
{
	void		*mlx;
	void		*win;
	int			i;
	int			j;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "fdf");
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if (tab[j][i] != 0)
				mlx_pixel_put(mlx, win, i, j, C_WHITE);
			i++;
		}
		j++;
	}
	deletemat(tab, y);
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
	createwindow(tab, x, y);
}
