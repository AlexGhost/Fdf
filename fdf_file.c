/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:23:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 17:47:03 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		deletemat(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	ft_memdel((void**) tab);
}

static int		**mallocmat(int x, int y)
{
	int **tab;
	int i;
	int j;

	i = 0;
	tab = ft_memalloc((size_t) y * sizeof(int*));
	while (i < y)
	{
		tab[i] = ft_memalloc((size_t) x * sizeof(int));
		i++;
	}
	return (tab);
}

int				fdf_checkfile(char *filename, int *x, int *y)
{
	int		fd;
	char	*line;
	char	**tab;

	line = NULL;
	tab = NULL;
	if ((fd = open(filename, O_RDONLY)))
	{
		if (fd < 0)
			return (0);
		while (get_next_line(fd, &line))
		{
			*x = 0;
			tab = ft_strsplit(line, ' ');
			while (tab[*x] != NULL)
				*x += 1;
			*y += 1;
			deletemat(tab);
		}
		close(fd);
		ft_strdel(&line);
	}
	else
		return (0);
	return (1);
}

int				fdf_readfile(char *filename, int x, int y)
{
	int		fd;
	char	*line;
	char	**tab;
	int		**tabi;
	int		i[2];

	line = NULL;
	tabi = mallocmat(x, y);
	fd = open(filename, O_RDONLY);
	i[1] = 0;
	while (get_next_line(fd, &line))
	{
		tab = NULL;
		tab = ft_strsplit(line, ' ');
		i[0] = 0;
		while (tab[i[0]])
		{
			tabi[i[1]][i[0]] = ft_atoi(tab[i[0]]);
			i[0]++;
		}
		i[1]++;
		deletemat(tab);
	}
	close(fd);
	ft_strdel(&line);
	fdf_displayfile(tabi, x, y);
	return (1);
}
