/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:53 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/14 18:29:46 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH 1300
# define WIN_HEIGHT 800
# define SIZE 15
# define ELEV 8
# define OFFSET 50

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_coord
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_coord;

typedef struct	s_line
{
	double		a;
	double		b;
	double		x;
	double		y;
	int			tmp;
}				t_line;

void			testdraw(void *mlx, void *win);
void			fdf_drawline(t_mlx smlx, t_coord coord, int color);
int				fdf_checkfile(char *filename, int *x, int *y);
int				fdf_readfile(int fd, int x, int y, int **tabi);
void			fdf_displayfile(int **tab, int x, int y);
int				**fdf_mallocmat(int x, int y);
int				fdf_getlength(char **tab);
void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h);

#endif
