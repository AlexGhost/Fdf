/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:45:13 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/14 18:08:20 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

static int		getcolor(int z)
{
	if (z < 1)
		return (C_BLUE);
	else if (z < 5)
		return (C_GREEN);
	else if (z < 8)
		return (C_BROWN);
	return (C_GRAY);
}

void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h)
{
	int			i;
	int			j;
	t_coord		coord;
	int			color;
	int			esp = 15;
	int			elev = 8;
	int			offset = 50;

	j = 0;
	while (j < h - 1)
	{
		i = 0;
		while (i < w - 1)
		{
			coord.x1 = (i * esp) + offset;
			coord.y1 = ((j * esp) - (tab[j][i] * elev)) + offset;
			coord.x2 = ((i + 1) * esp) + offset;
			coord.y2 = ((j * esp) - (tab[j][i + 1] * elev)) + offset;
			fdf_drawline(smlx, coord, getcolor(tab[j][i]));
			coord.x1 = (i * esp) + offset;
			coord.y1 = ((j * esp) - (tab[j][i] * elev)) + offset;
			coord.x2 = (i * esp) + offset;
			coord.y2 = (((j + 1) * esp) - (tab[j + 1][i] * elev)) + offset;
			fdf_drawline(smlx, coord, getcolor(tab[j][i]));
			coord.x1 = (i * esp) + offset;
			coord.y1 = (((h - 1) * esp) - (tab[h - 1][i] * elev)) + offset;
			coord.x2 = ((i + 1) * esp) + offset;
			coord.y2 = (((h - 1) * esp) - (tab[h - 1][i + 1] * elev)) + offset;
			fdf_drawline(smlx, coord, getcolor(tab[j][i]));
			i++;
		}
		coord.x1 = (i * esp) + offset;
		coord.y1 = ((j * esp) - (tab[j][i] * elev)) + offset;
		coord.x2 = (i * esp) + offset;
		coord.y2 = (((j + 1) * esp) - (tab[j + 1][i] * elev)) + offset;
		fdf_drawline(smlx, coord, getcolor(tab[j][i]));
		j++;
	}
}
