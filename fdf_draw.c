/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:11:42 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/14 16:46:24 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	hor_line(t_mlx smlx, t_coord coord, int color)
{
	while (coord.y1 != coord.y2)
	{
		mlx_pixel_put(smlx.mlx, smlx.win, coord.x1, coord.y1, color);
		(coord.y1 < coord.y2 ? ++coord.y1 : --coord.y1);
	}
}

static void	ver_line(t_mlx smlx, t_coord coord, int color)
{
	while (coord.x1 != coord.x2)
	{
		mlx_pixel_put(smlx.mlx, smlx.win, coord.x1, coord.y1, color);
		(coord.x1 < coord.x2 ? ++coord.x1 : --coord.x1);
	}
}

static void	incr_x(t_mlx smlx, t_line l, t_coord coord, int color)
{
	while (l.x != coord.x2)
	{
		l.y = l.a * l.x + l.b;
		mlx_pixel_put(smlx.mlx, smlx.win, (int)l.x, (int)l.y, color);
		(l.x > coord.x2 ? --l.x : ++l.x);
	}
}

static void	incr_y(t_mlx smlx, t_line l, t_coord coord, int color)
{
	while (l.y != coord.y2)
	{
		l.x = (l.y - l.b) / l.a;
		mlx_pixel_put(smlx.mlx, smlx.win, (int)l.x, (int)l.y, color);
		(l.y > coord.y2 ? --l.y : ++l.y);
	}
}

void		fdf_drawline(t_mlx smlx, t_coord coord, int color)
{
	t_line l;

	if (coord.x1 == coord.x2 && coord.y1 != coord.y2)
		hor_line(smlx, coord, color);
	else if (coord.y1 == coord.y2 && coord.x1 != coord.x2)
		ver_line(smlx, coord, color);
	else
	{
		l.a = (coord.y1 - coord.y2) / (double)(coord.x1 - coord.x2);
		l.b = coord.y1 - (l.a * coord.x1) + 0.5;
		l.x = coord.x1;
		l.y = coord.y1;
		if (fabs(l.a) <= 1)
			incr_x(smlx, l, coord, color);
		else
			incr_y(smlx, l, coord, color);
	}
}
