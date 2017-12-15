/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:23:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/15 15:19:31 by acourtin         ###   ########.fr       */
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

static void		filltab(char ***tab, int **y, char **line)
{
	*tab = ft_strsplit(*line, ' ');
	**y += 1;
	ft_strdel(line);
}

int				fdf_checkfile(char *filename, int *x, int *y, int ok)
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
			ok = 1;
			if (tab)
				deletemat(tab);
			filltab(&tab, &y, &line);
		}
		if (i == -1 || ok == 0)
			return (0);
		*x = fdf_getlength(tab);
		deletemat(tab);
		close(fd);
		ft_strdel(&line);
	}
	else
		return (0);
	return (1);
}

int				fdf_readfile(int fd, int x, int y, int **tabi)
{
	char	*line;
	char	**tab;
	int		i[2];

	tabi = fdf_mallocmat(x, y);
	i[1] = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		i[0] = 0;
		while (tab[i[0]])
		{
			if (ft_isdigit(*tab[i[0]]) == 0 && *tab[i[0]] != '-')
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
