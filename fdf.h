/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:53 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/13 17:20:31 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH 1300
# define WIN_HEIGHT 800

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_coord
{
	int			c[2];
	int			dc[2];
	int			lc[2];
	int			*err;
}				t_coord;

void			testdraw(void *mlx, void *win);
void			fdf_drawline(void *mlx, void *win, int coord[], int color);
int				fdf_checkfile(char *filename, int *x, int *y);
int				fdf_readfile(int fd, int x, int y, int **tabi);
void			fdf_displayfile(int **tab, int x, int y);
int				**fdf_mallocmat(int x, int y);
int				fdf_getlength(char **tab);
void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h);

#endif
