/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:23:05 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/11 17:40:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_readfile(char *filename)
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
				{
					//afficher le point
					ft_putstr(tab[i]);
					ft_putstr(" ");
					i++;
				}
				ft_putchar('\n');
			}
		}
	}
	else
		return (0);
	return (1);
}
