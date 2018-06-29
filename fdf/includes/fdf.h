/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:19:33 by afrantzi          #+#    #+#             */
/*   Updated: 2018/06/24 19:44:45 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define SIZE 1000
# define X(i, j, b, s) j * b + s - (b * i)
# define Y(i, j, b, s) (i + j) * b + s
# define C(x, y) 0xFFFFFF - abs(x * y * 2000)

typedef struct	s_map
{
	void	*mlx;
	void	*win;
	int		col;
	int		row;
	int		v;
	int		h;
	int		m;
	int		c;
	int		xb;
	int		yb;
	int		**val;
}				t_map;

void			error(int i);
void			draw_map(t_map *m);
t_map			*get_data(t_map *m, char *file, int fd, int i);

#endif
