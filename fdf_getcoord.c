/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_getcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:23:45 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/16 19:14:08 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		convert_iso(t_coord *c)
{
	c->x1 = (c->x1) + ((c->y1) / 3);
	c->x2 = (c->x2) + ((c->y2) / 3);
	c->y1 = c->y1;
	c->y2 = c->y2;
}

static void		getsize(int *w)
{
	int i;

	i = 1;
	if ((*w * i) < WIN_WIDTH)
	{
		while ((*w * i) < WIN_WIDTH)
		{
			i++;
		}
		i *= 0.80;
	}
	*w = i;
	*w *= 1.5;
}

void			fdf_getcoord_hor(t_coord *c, int **tab, int i[2], int w)
{
	getsize(&w);
	c->x1 = (i[0] * (w * SIZE)) + OFFSET;
	c->y1 = ((i[1] * (w * SIZE)) - (tab[i[1]][i[0]] * ELEV)) + OFFSET;
	c->x2 = ((i[0] + 1) * (w * SIZE)) + OFFSET;
	c->y2 = ((i[1] * (w * SIZE)) - (tab[i[1]][i[0] + 1] * ELEV)) + OFFSET;
	convert_iso(c);
}

void			fdf_getcoord_ver(t_coord *c, int **tab, int i[2], int w)
{
	getsize(&w);
	c->x1 = (i[0] * (w * SIZE)) + OFFSET;
	c->y1 = ((i[1] * (w * SIZE)) - (tab[i[1]][i[0]] * ELEV)) + OFFSET;
	c->x2 = (i[0] * (w * SIZE)) + OFFSET;
	c->y2 = (((i[1] + 1) * (w * SIZE)) - (tab[i[1] + 1][i[0]] * ELEV)) + OFFSET;
	convert_iso(c);
}
