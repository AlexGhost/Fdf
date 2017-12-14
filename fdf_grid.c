/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:45:13 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/14 16:47:21 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h)
{
	int			i;
	int			j;
	t_coord		coord;
	int			esp = 25;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w - 1)
		{
			coord.x1 = i * esp;
			coord.y1 = (j * esp) - tab[j][i];
			coord.x2 = (i + 1) * esp;
			coord.y2 = (j * esp) - tab[j][i + 1];
			fdf_drawline(smlx, coord, C_WHITE);
			i++;
		}
		j++;
	}
}
