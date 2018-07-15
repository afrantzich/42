/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:52:35 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/07 17:41:42 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

static int	count_neighbors(t_node **n, int i, int j)
{
	int count;

	count = 0;
	count += (i > 0 && j > 0 && n[i - 1][j - 1].alive == 1) ? 1 : 0;
	count += (i > 0 && n[i - 1][j].alive == 1) ? 1 : 0;
	count += (i > 0 && j < COLS - 1 && n[i - 1][j + 1].alive == 1) ? 1 : 0;
	count += (j > 0 && n[i][j - 1].alive == 1) ? 1 : 0;
	count += (j < COLS - 1 && n[i][j + 1].alive == 1) ? 1 : 0;
	count += (i < ROWS - 1 && j > 0 && n[i + 1][j - 1].alive == 1) ? 1 : 0;
	count += (i < ROWS - 1 && n[i + 1][j].alive == 1) ? 1 : 0;
	count += (i < ROWS - 1 && j < COLS - 1 && n[i + 1][j + 1].alive == 1) ? 1 : 0;
	return (count);
}

void	populate(t_node *n)
{
	if (n->neighbors < 2 || n->neighbors > 3)
		n->alive = 0;
	else if (n->neighbors == 3)
		n->alive = 1;
}

int			move(t_all *m)
{
	int i;
	int j;

	mlx_clear_window(m->mlx, m->win);
	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS)
			m->map[i][j].neighbors = count_neighbors(m->map, i, j);
	}
	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS)
			populate(&m->map[i][j]);
	}
	draw_map(m);
	usleep(80000);
	return (0);
}
