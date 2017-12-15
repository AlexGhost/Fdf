/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:24:42 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/15 15:48:43 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**fdf_mallocmat(int x, int y)
{
	int **tab;
	int i;

	i = 0;
	tab = ft_memalloc((size_t)y * sizeof(int*));
	while (i < y)
	{
		tab[i] = ft_memalloc((size_t)x * sizeof(int));
		i++;
	}
	return (tab);
}

int			fdf_getlength(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i += 1;
	return (i);
}
