/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:53:20 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/16 13:57:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	exitfdf(int keycode)
{
	if (keycode == 53)
	{
		ft_putendl("fdf shutting down");
		exit(0);
	}
	return (0);
}

static void	createwindow(int **tab, int x, int y)
{
	t_mlx		smlx;

	smlx.mlx = mlx_init();
	smlx.win = mlx_new_window(smlx.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	fdf_drawisogrid(smlx, tab, x, y);
	deletemat(tab, y);
	mlx_key_hook(smlx.win, exitfdf, 0);
	mlx_loop(smlx.mlx);
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
