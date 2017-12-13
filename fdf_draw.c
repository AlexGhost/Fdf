/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:11:42 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/13 18:22:13 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_drawline(void *mlx, void *win, int coord[4], int color)
{
	double a;
	double b;
	double i;
	double j;

	if (coord[0] == coord[2])
		while (coord[1] < coord[3])
			mlx_pixel_put(mlx, win, coord[0], coord[1]++, color);
	else
		a = (coord[1] - coord[3]) / (double)(coord[0] - coord[2]);
	b = coord[1] - (a * coord[0]) + 0.5;
	j = coord[1];
	i = coord[0];
	while (i <= coord[2])
	{
		mlx_pixel_put(mlx, win, (int)i, (int)j - 1, color);
		j = a * i + b;
		i++;
	}
		j++;
	mlx_pixel_put(mlx, win, coord[0], coord[1], color);
	mlx_pixel_put(mlx, win, coord[2], coord[3], color);
}
