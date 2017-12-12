/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:23:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 15:18:57 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_checkfile(char *filename, int *x, int *y)
{
	int		fd;
	char	*line;
	char	**tab;
	int		i;

	line = NULL;
	tab = NULL;
	if ((fd = open(filename, O_RDONLY)))
	{
		if (fd < 0)
			return (0);
		while (get_next_line(fd, &line))
		{
			tab = ft_strsplit(line, ' ');
			if (tab)
			{
				i = 0;
				while (tab[i] != NULL)
					i++;
				*x = i;
				*y += 1;
			}
		}
		close(fd);
	}
	else
		return (0);
	return (1);
}

int		fdf_readfile(char *filename, int x, int y)
{
	int		fd;
	char	*line;
	char	**tab;
	int		tabi[y][x];
	int		i[2];

	line = NULL;
	tab = NULL;
	tabi[0][0] = 0;
	fd = open(filename, O_RDONLY);
	i[1] = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		if (tab)
		{
			i[0] = 0;
			while (tab[i[0]] != NULL)
			{
				tabi[i[1]][i[0]] = ft_atoi(tab[i[0]]);
				i[0]++;
			}
		}
		i[1]++;
	}
	close(fd);
	i[1] = 0;
	while (i[1] < y)
	{
		i[0] = 0;
		while (i[0] < x)
		{
			ft_putnbr(tabi[i[1]][i[0]]);
			ft_putchar(' ');
			i[0]++;
		}
		ft_putchar('\n');
		i[1]++;
	}
	return (1);
}
