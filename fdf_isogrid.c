/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isogrid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:29:24 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/15 15:48:23 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

static int		getcolor(int z)
{
	if (z < 0)
		return (C_ALT1);
	else if (z == 0)
		return (C_ALT2);
	return (C_ALT3);
}

void			fdf_drawisogrid(t_mlx smlx, int **tab, int w, int h)
{
	int			i[2];
	t_coord		coord;

	i[1] = 0;
	while (i[1] < h - 1)
	{
		i[0] = 0;
		while (i[0] < w - 1)
		{
			fdf_getcoord_hor(&coord, tab, i);
			fdf_drawline(smlx, coord, getcolor(tab[i[1]][i[0]]));
			fdf_getcoord_ver(&coord, tab, i);
			fdf_drawline(smlx, coord, getcolor(tab[i[1]][i[0]]));
			fdf_getcoord_lasthor(&coord, tab, i, h);
			fdf_drawline(smlx, coord, getcolor(tab[i[1]][i[0]]));
			i[0]++;
		}
		fdf_getcoord_ver(&coord, tab, i);
		fdf_drawline(smlx, coord, getcolor(tab[i[1]][i[0]]));
		i[1]++;
	}
}
