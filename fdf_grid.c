/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:45:13 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/13 15:06:35 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "fdf_colors.h"

void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h)
{
	int i;
	int j;

	j = 0;
	while (j < h)
	{
		i = 0;
		while (i < w)
		{
			if (tab[j][i] != 0)
				mlx_pixel_put(smlx.mlx, smlx.win, i, j, C_WHITE);
			i++;
		}
		j++;
	}
}
