/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:18:17 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/08 12:46:54 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "gol.h"

void	free_stuff(t_all *m)
{
	int i;

	i = -1;
	while (++i < ROWS)
		free(m->map[i]);
	free(m->map);
}

void	quit_restart(t_all *m, int q)
{
	free_stuff(m);
	if (q == 1)
		init_node_map(m->map);
	else if (q == 0)
		exit(0);
}

static int	deal_key(int key, t_all *m)
{
	if (key == 49 || key == 36)
		quit_restart(m, 1);
	if (key == 53)
		quit_restart(m, 0);
	return (0);
}

int			main(void)
{
	t_all	m;
	t_node	**node_map = NULL;

	srand(time(0));
	node_map = init_node_map(node_map);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, HEIGHT, WIDTH, "Game of Life");
	m.map = node_map;
	draw_map(&m);
	mlx_key_hook(m.win, deal_key, &m);
	mlx_loop_hook(m.mlx, move, &m);
	mlx_loop(m.mlx);
}
