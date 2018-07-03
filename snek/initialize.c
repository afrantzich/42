/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:24:01 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/03 15:58:48 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "snek.h"

t_node	*init_node(t_node *body)
{
	body = (t_node*)malloc(sizeof(t_node));
	body->x = -CELL;
	body->y = -CELL;
	body->next = NULL;
	return (body);
}

t_node		*spawn_apple(t_node *a, t_map *m, t_node *traverse)
{
	a->x = (rand() % (WIDTH / CELL - 1)) * CELL + CELL / 2;
	a->y = (rand() % (HEIGHT / CELL - 1)) * CELL + CELL / 2;
	traverse = m->chain;
	while (traverse)
	{
		if (a->x == traverse->x && a->y == traverse->y)
			spawn_apple(a, m, traverse);
		traverse = traverse->next;
	}
	if (a->x == m->x && a->y == m->y)
		spawn_apple(a, m, traverse);
	a->next = NULL;
	return (a);
}

t_map	*init_map(t_map *m)
{
	t_node *apple = NULL;
	t_node *body = NULL;
	t_node *body2 = NULL;
	t_node *traverse = NULL;
	apple = init_node(apple);
	body = init_node(body);
	body2 = init_node(body2);
	m->apple = apple;
	body->next = body2;
	m->d = 'd';
	m->x = CELL / 2 * 15;
	m->y = CELL / 2 * 9;
	body->x = m->x - CELL;
	body->y = m->y;
	body2->x = body->x - CELL;
	body2->y = body->y;
	m->len = 3;
	m->chain = body;
	m->game_over = 0;
	apple = spawn_apple(apple , m, traverse);
	return (m);
}
