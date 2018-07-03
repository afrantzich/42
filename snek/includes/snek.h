/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snek.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:19:33 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/03 15:50:03 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNEK_H
# define SNEK_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
/*resolution is 2560 x 1440, GCF is 160*/
# define HEIGHT 1280
# define WIDTH 1216
# define CELL 32

typedef struct	s_node
{
	int	x;
	int	y;
	struct s_node *next;
}				t_node;

typedef struct	s_map
{
	void	*mlx;
	void	*win;
	void	*img;
	char	d;
	int		x;
	int		y;
	int		len;
	int		game_over;
	t_node	*chain;
	t_node	*apple;
}				t_map;

t_map	*init_map(t_map *m);
t_node	*init_node(t_node *body);
t_node	*spawn_apple(t_node *a, t_map *m, t_node *traverse);
int		move(t_map *m);
void	draw_map(t_map *m);

#endif
