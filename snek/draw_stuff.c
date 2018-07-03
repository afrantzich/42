/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:46:48 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/03 15:50:08 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snek.h"

void	draw_cell(t_map *m, int x, int y, int color)
{
	int i;
	int j;

	i = -CELL / 2 + CELL / 10 - 1;
	while (++i < CELL / 2 - CELL / 10)
	{
		j = -CELL / 2 + CELL / 10 - 1;
		while (++j < CELL / 2 - CELL / 10)
			mlx_pixel_put(m->mlx, m->win, x + j, y + i, color);
	}
}

void	draw_map(t_map *m)
{
	t_node *traverse;

	traverse = m->chain;
	draw_cell(m, m->x, m->y, 0x2eb82e);
	draw_cell(m, m->apple->x, m->apple->y, 0xff0000);
	while (traverse)
	{
		draw_cell(m, traverse->x, traverse->y, 0x2eb82e);
		traverse = traverse->next;
	}
}
