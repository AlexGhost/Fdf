/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:06:01 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 20:10:19 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			**fdf_mallocmat(int x, int y)
{
	int **tab;
	int i;
	int j;

	i = 0;
	tab = ft_memalloc((size_t)y * sizeof(int*));
	while (i < y)
	{
		tab[i] = ft_memalloc((size_t)x * sizeof(int));
		i++;
	}
	return (tab);
}
