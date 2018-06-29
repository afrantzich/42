/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:18:17 by afrantzi          #+#    #+#             */
/*   Updated: 2018/06/24 19:49:04 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ecscapetehprgrm(t_map *m)
{
	while (m->row--)
		ft_memdel((void**)&m->val[m->row]);
	ft_memdel((void**)&m->val);
	exit(0);
}

static int	deal_key(int key, t_map *m)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == 126)
		m->v += m->yb;
	else if (key == 125)
		m->v -= m->yb;
	else if (key == 124)
		m->h -= m->xb / 2;
	else if (key == 123)
		m->h += m->xb / 2;
	else if (key == 24 || key == 69)
	{
		m->xb += 10;
		m->yb += 4;
	}
	else if (key == 27 || key == 78)
	{
		m->xb -= 10;
		m->yb -= 4;
	}
	else if (key == 49)
		m->c += (m->c < 100) ? 1 : -99;
	else if (key == 53)
		ecscapetehprgrm(m);
	draw_map(m);
	return (0);
}

static int	deal_mouse(int key, int x, int y, t_map *m)
{
	mlx_clear_window(m->mlx, m->win);
	if (key == 4)
		m->m += 1;
	else if (key == 5)
		m->m -= 1;
	else if (key == 1)
	{
		m->h = x - m->xb;
		m->v = y - m->yb;
	}
	draw_map(m);
	return (0);
}

void		error(int i)
{
	if (i == 0)
		ft_putstr("fdf must have exactly 1 parameter\n");
	else if (i == 1)
		ft_putstr("invalid file\n");
	exit(0);
}

int			main(int ac, char **av)
{
	t_map m;

	if (ac != 2)
		error(0);
	m = *get_data(&m, av[1], 0, 0);
	if (m.row == 0)
		error(1);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, SIZE, SIZE, "hey look a window");
	draw_map(&m);
	mlx_key_hook(m.win, deal_key, &m);
	mlx_mouse_hook(m.win, deal_mouse, &m);
	mlx_loop(m.mlx);
}
