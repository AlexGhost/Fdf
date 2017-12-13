/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:45:13 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/13 17:15:30 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h)
{
	int i;
	int j;
	int coord[4];
	int esp = 10;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w - 1)
		{
			/*coord[0] = i * esp;
			coord[1] = (j * esp) - tab[j][i];
			coord[2] = (i + 1) * esp;
			coord[3] = (j * esp) - tab[j][i + 1];*/
			coord[0] = 50;
			coord[1] = 50;
			coord[2] = 150;
			coord[3] = 150;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
			coord[0] = 50;
			coord[1] = 100;
			coord[2] = 150;
			coord[3] = 100;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
			coord[0] = 50;
			coord[1] = 150;
			coord[2] = 150;
			coord[3] = 50;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
			coord[0] = 100;
			coord[1] = 50;
			coord[2] = 100;
			coord[3] = 150;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
			coord[0] = 300;
			coord[1] = 300;
			coord[2] = 500;
			coord[3] = 600;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
			coord[0] = 500;
			coord[1] = 200;
			coord[2] = 550;
			coord[3] = 50;
			fdf_drawline(smlx.mlx, smlx.win, coord, C_WHITE);
				//mlx_pixel_put(smlx.mlx, smlx.win, i, j, C_WHITE);
			i++;
		}
		j++;
	}
}
