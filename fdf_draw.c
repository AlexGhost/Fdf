/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:11:42 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 18:34:47 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

static void	fdfinit(int coord[], int *dc, int *lengthc, int *c)
{
	c[0] = coord[0];
	c[1] = coord[1];
	lengthc[0] = ft_abs(coord[2] - coord[0]);
	lengthc[1] = ft_abs(coord[3] - coord[1]);
	if ((coord[2] - coord[0]) > 0)
		dc[0] = 1;
	else if ((coord[2] - coord[0]) < 0)
		dc[0] = -1;
	else
		dc[0] = 0;
	if ((coord[3] - coord[1]) > 0)
		dc[1] = 1;
	else if ((coord[3] - coord[1]) < 0)
		dc[1] = -1;
	else
		dc[1] = 0;
}

static void	changecoord1(int c[], int dc[], int error, int lengthc[])
{
	c[0] += dc[0];
	error += lengthc[1];
	if (error > lengthc[0])
	{
		error -= lengthc[0];
		c[1] += dc[1];
	}
}

static void	changecoord2(int c[], int dc[], int error, int lengthc[])
{
	c[0] += dc[0];
	error += lengthc[1];
	if (error > lengthc[0])
	{
		error -= lengthc[0];
		c[1] += dc[1];
	}
}

/*
**		var[0] : coord
**		var[1] : direction coord
**		var[2] : longueur coord
**		var[3] : erreur
*/

void		fdf_drawline(void *mlx, void *win, int coord[], int color)
{
	int		var[4][2];
	int		i;

	i = 0;
	fdfinit(coord, var[1], var[2], var[0]);
	if (var[2][0] > var[2][1])
	{
		var[3][0] = var[2][0] / 2;
		while (i++ < var[2][0])
		{
			changecoord1(var[0], var[1], var[3][0], var[2]);
			mlx_pixel_put(mlx, win, var[0][0], var[0][1], color);
		}
	}
	else
	{
		var[3][0] = var[2][1] / 2;
		while (i++ < var[2][1])
		{
			changecoord2(var[0], var[1], var[3][0], var[2]);
			mlx_pixel_put(mlx, win, var[0][0], var[0][1], color);
		}
	}
	mlx_pixel_put(mlx, win, coord[0], coord[1], color);
	mlx_pixel_put(mlx, win, coord[2], coord[3], color);
}

void		testdraw(void *mlx, void *win)
{
	int i;
	int color;
	int coord[4];

	color = C_WHITE;
	i = 0;
	coord[0] = 0;
	coord[1] = 0;
	coord[2] = 0;
	coord[3] = 0;
	while (i < 360)
	{
		coord[2] += i / 10;
		coord[3] += i / 2;
		fdf_drawline(mlx, win, coord, color);
		i++;
	}
}
