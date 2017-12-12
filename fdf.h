/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 11:34:53 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/12 20:10:20 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

void			testdraw(void *mlx, void *win);
void			fdf_drawline(void *mlx, void *win, int coord[], int color);
int				fdf_checkfile(char *filename, int *x, int *y);
int				fdf_readfile(char *filename, int x, int y);
void			fdf_displayfile(int **tab, int x, int y);
int				**fdf_mallocmat(int x, int y);

#endif
