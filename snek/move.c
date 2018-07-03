/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:52:35 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/03 12:54:06 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snek.h"

static void	shift_body(t_map *m, t_node *body)
{
	while (body->next)
	{
		if (body->next->next == NULL)
		{
			body->next->next = m->chain;
			m->chain = body->next;
			body->next = NULL;
			break ;
		}
		body = body->next;
	}
	m->chain->x = m->x;
	m->chain->y = m->y;
}

static void	grow_body(t_map *m)
{
	t_node	*body = NULL;
	t_node	*traverse;

	body = init_node(body);
	traverse = m->chain;
	while (traverse->next)
		traverse = traverse->next;
	traverse->next = body;
	body->x = traverse->x;
	body->y = traverse->y;
	m->len++;
}

static void	check_status(t_map *m)
{
	t_node *traverse;

	traverse = m->chain->next;
	if (m->x < 0 || m->x > WIDTH || m->y < 0 || m->y > HEIGHT)
		m->game_over = 1;
	else if (m->x == m->apple->x && m->y == m->apple->y)
	{
		spawn_apple(m->apple, m, traverse);
		grow_body(m);
	}
	while (traverse->next)
	{
		traverse = traverse->next;
		if (traverse->x == m->x && traverse->y == m->y)
			m->game_over = 1;
	}
}

int		move(t_map *m)
{
	if (m->game_over == 0)
	{
		shift_body(m, m->chain);
		if (m->d == 'w')
			m->y -= CELL;
		else if (m->d == 'a')
			m->x -= CELL;
		else if (m->d == 's')
			m->y += CELL;
		else if (m->d == 'd')
			m->x += CELL;
		check_status(m);
		if (m->game_over != 0)
			return (0);
		mlx_clear_window(m->mlx, m->win);
		draw_map(m);
	}
	usleep(80000);
	return (0);
}
