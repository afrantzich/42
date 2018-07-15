/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:19:33 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/08 12:46:50 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOL_H
# define GOL_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
/*resolution is 2560 x 1440, GCF is 160*/
# define HEIGHT 1280
# define WIDTH 1216
# define CELL 4
# define ROWS HEIGHT / CELL - 1
# define COLS WIDTH / CELL - 1

typedef struct	s_node
{
	int	x;
	int	y;
	int	neighbors;
	int alive;
}				t_node;

typedef struct	s_all
{
	void	*mlx;
	void	*win;
	t_node	**map;
}				t_all;

t_node	**init_node_map(t_node **n);
void	draw_map(t_all *m);
int		move(t_all *m);

#endif
