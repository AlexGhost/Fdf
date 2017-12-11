/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:34 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/11 17:43:38 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int ac, char **av)
{
	void	*mlx;
	void		*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "fdf");
	if (ac != 2)
	{
		ft_putendl("usage: <filename> | name of fdf file");
		return (0);
	}
	if (fdf_readfile(av[1]))
		ft_putendl("file valid");
	mlx_loop(mlx);
	return (0);
}
