/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/15 15:17:23 by acourtin         ###   ########.fr       */
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
	else if (fdf_checkfile(av[1], &x, &y, 0))
	{
		ft_putstr("x: ");
		ft_putnbr(x);
		ft_putstr("  y: ");
		ft_putnbr(y);
		ft_putchar('\n');
		if (fdf_readfile(open(av[1], O_RDONLY), x, y, NULL) == 0)
		{
			ft_putendl("error: file invalid");
			return (0);
		}
	}
	return (0);
}
