/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:23:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 20:26:55 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		deletemat(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static int		getlength(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
		i += 1;
	return (i);
}

int				fdf_checkfile(char *filename, int *x, int *y)
{
	int		fd;
	int		i;
	char	*line;
	char	**tab;

	if ((fd = open(filename, O_RDONLY)) > 0)
	{
		tab = NULL;
		while ((i = get_next_line(fd, &line)) == 1)
		{
			if (tab)
				deletemat(tab);
			tab = ft_strsplit(line, ' ');
			*y += 1;
			ft_strdel(&line);
		}
		ft_strdel(&line);
		if (i == -1)
			return (0);
		*x = getlength(tab);
		deletemat(tab);
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

	tabi = fdf_mallocmat(x, y);
	fd = open(filename, O_RDONLY);
	i[1] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i[0] = 0;
		while (tab[i[0]])
		{
			if (ft_isdigit(*tab[i[0]]) == 0)
				return (0);
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
