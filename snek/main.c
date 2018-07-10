/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:18:17 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/08 21:46:22 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "snek.h"

void	free_stuff(t_map *m)
{
	t_node *traverse;
	t_node *save;

	traverse = m->chain;
	while (traverse)
	{
		save = traverse->next;
		ft_memdel((void**)&traverse);
		traverse = save;
	}
}

void	quit_restart(t_map *m, int q)
{
	free_stuff(m);
	if (q == 1)
		init_map(m);
	else if (q == 0)
		exit(0);
}

static int	deal_key(int key, t_map *m)
{
	if (key == 53)
		quit_restart(m, 0);
	if (m->game_over == 0)
	{
		if ((key == 126 || key == 13) && m->d != 's')
			m->d = 'w';
		else if ((key == 123 || key == 0) && m->d != 'd')
			m->d = 'a';
		else if ((key == 125 || key == 1) && m->d != 'w')
			m->d = 's';
		else if ((key == 124 || key == 2) && m->d != 'a')
			m->d = 'd';
		move(m);
	}
	else if (key == 49 || key == 36)
		quit_restart(m, 1);
	return (0);
}

int			main(void)
{
	t_map	m;

	srand(time(0));
	m = *init_map(&m);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "snek");
	draw_map(&m);
	mlx_key_hook(m.win, deal_key, &m);
	mlx_loop_hook(m.mlx, move, &m);
	mlx_loop(m.mlx);
}
