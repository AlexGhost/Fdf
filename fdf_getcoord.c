/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_getcoord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:23:45 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/15 15:53:28 by acourtin         ###   ########.fr       */
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

void			fdf_getcoord_hor(t_coord *c, int **tab, int i[2])
{
	c->x1 = (i[0] * SIZE) + OFFSET;
	c->y1 = ((i[1] * SIZE) - (tab[i[1]][i[0]] * ELEV)) + OFFSET;
	c->x2 = ((i[0] + 1) * SIZE) + OFFSET;
	c->y2 = ((i[1] * SIZE) - (tab[i[1]][i[0] + 1] * ELEV)) + OFFSET;
	convert_iso(c);
}

void			fdf_getcoord_ver(t_coord *c, int **tab, int i[2])
{
	c->x1 = (i[0] * SIZE) + OFFSET;
	c->y1 = ((i[1] * SIZE) - (tab[i[1]][i[0]] * ELEV)) + OFFSET;
	c->x2 = (i[0] * SIZE) + OFFSET;
	c->y2 = (((i[1] + 1) * SIZE) - (tab[i[1] + 1][i[0]] * ELEV)) + OFFSET;
	convert_iso(c);
}

void			fdf_getcoord_lasthor(t_coord *c, int **tab, int i[2], int h)
{
	c->x1 = (i[0] * SIZE) + OFFSET;
	c->y1 = (((h - 1) * SIZE) - (tab[h - 1][i[0]] * ELEV)) + OFFSET;
	c->x2 = ((i[0] + 1) * SIZE) + OFFSET;
	c->y2 = (((h - 1) * SIZE) - (tab[h - 1][i[0] + 1] * ELEV)) + OFFSET;
	convert_iso(c);
}
