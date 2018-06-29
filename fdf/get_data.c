/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 22:42:22 by afrantzi          #+#    #+#             */
/*   Updated: 2018/06/27 20:35:15 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_map	*init_map(t_map *m)
{
	m->mlx = NULL;
	m->win = NULL;
	m->col = 0;
	m->row = 0;
	m->v = 0;
	m->h = 0;
	m->m = 1;
	m->xb = 0;
	m->yb = 0;
	return (m);
}

static void		more_data(t_map *m)
{
	m->xb = SIZE / (2 * m->col);
	if (m->xb < 5)
		m->xb = 5;
	m->yb = (int)(m->xb * 0.4);
	m->h = (SIZE / 2 - abs(m->col - m->row) / 2 * m->xb) - m->xb;
	m->v = SIZE / 2 - abs(m->col - m->row) * m->yb;
	m->val = (int**)malloc(sizeof(int*) * (m->row));
}

static void		verify_map(t_map *m, char *line)
{
	if (m->row == 1)
		m->col = ft_countwords(line, ' ');
	else if (ft_countwords(line, ' ') != m->col)
		error(1);
}

t_map			*get_data(t_map *m, char *file, int fd, int i)
{
	char	*line;

	m = init_map(m);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (m);
	while (get_next_line(fd, &line) > 0)
	{
		m->row += 1;
		verify_map(m, line);
		ft_memdel((void**)&line);
	}
	close(fd);
	if (m->col == 0)
		error(1);
	more_data(m);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (m);
	while (get_next_line(fd, &line) > 0)
	{
		m->val[i++] = ft_nbrsplit(line, ' ');
		ft_memdel((void**)&line);
	}
	return (m);
}
