/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:46:48 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/08 12:46:52 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gol.h"

void	draw_cell(t_all *m, int x, int y, int color)
{
	int i;
	int j;

	i = -CELL / 2 + CELL / 10 - 1;
	while (++i < CELL / 2 - CELL / 4)
	{
		j = -CELL / 2 + CELL / 10 - 1;
		while (++j < CELL / 2 - CELL / 4)
			mlx_pixel_put(m->mlx, m->win, x + j, y + i, color);
	}
}

void	draw_map(t_all *m)
{
	int i;
	int j;

	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS)
		{
			if (m->map[i][j].alive == 1)
				draw_cell(m, m->map[i][j].x, m->map[i][j].y, 0xffffff);
		}
	}
}
