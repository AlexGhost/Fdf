/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 18:06:30 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (ac != 2)
	{
		ft_putendl("usage: <filename> | name of fdf file");
		return (0);
	}
	else if (fdf_checkfile(av[1], &x, &y))
	{
		ft_putendl("file valid");
		ft_putstr("x: ");
		ft_putnbr(x);
		ft_putstr("  y: ");
		ft_putnbr(y);
		ft_putchar('\n');
		fdf_readfile(av[1], x, y);
	}
	while (1);
	return (0);
}
