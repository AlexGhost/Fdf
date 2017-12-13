/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:53 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/13 15:04:16 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

void			testdraw(void *mlx, void *win);
void			fdf_drawline(void *mlx, void *win, int coord[], int color);
int				fdf_checkfile(char *filename, int *x, int *y);
int				fdf_readfile(int fd, int x, int y, int **tabi);
void			fdf_displayfile(int **tab, int x, int y);
int				**fdf_mallocmat(int x, int y);
int				fdf_getlength(char **tab);
void			fdf_drawgrid(t_mlx smlx, int **tab, int w, int h);

#endif
