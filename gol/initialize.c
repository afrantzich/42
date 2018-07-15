/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:24:01 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/08 12:47:03 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "gol.h"

t_node		**init_node_map(t_node **n)
{
	int i;
	int j;

	srand(time(0));
	n = (t_node**)malloc(sizeof(t_node*) * ROWS);
	i = -1;
	ft_putnbr(ROWS);
	ft_putnbr(COLS);
	while (++i < ROWS)
	{
		n[i] = (t_node*)malloc(sizeof(t_node) * COLS);
	}
	i = -1;
	while (++i < ROWS)
	{
		j = -1;
		while (++j < COLS)
		{
			n[i][j].x = i * CELL + CELL / 2;
			n[i][j].y = j * CELL + CELL / 2;
			n[i][j].neighbors = 0;
			n[i][j].alive = rand() % 2;
		}
	}
	return (n);
}
