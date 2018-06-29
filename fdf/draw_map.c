/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:44:01 by afrantzi          #+#    #+#             */
/*   Updated: 2018/06/24 19:40:07 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*new_line(int x1, int x2, int y1, int y2)
{
	int *line;

	if ((line = (int*)malloc(sizeof(int) * 4)) == NULL)
		return (NULL);
	line[0] = x1;
	line[1] = x2;
	line[2] = y1;
	line[3] = y2;
	return (line);
}

static void	small_slope(t_map *m, int *line, float s, int clr)
{
	float	c;
	int		neg;

	c = 0;
	neg = 1;
	if (s < 0)
		neg = -1;
	while (line[0] < line[1])
	{
		c += s * neg;
		if (c > 0.5)
		{
			line[2] += neg;
			c--;
		}
		mlx_pixel_put(m->mlx, m->win, line[0]++, line[2], C(clr, m->c));
	}
}

static void	big_slope(t_map *m, int *line, float s, int clr)
{
	float	c;
	int		neg;

	c = 0;
	neg = 1;
	if (s < 0)
		neg = -1;
	while (line[2] < line[3])
	{
		c += 1 / s * neg;
		if (c > 0.5)
		{
			line[0] += neg;
			c--;
		}
		mlx_pixel_put(m->mlx, m->win, line[0], line[2]++, C(clr, m->c));
	}
}

static void	draw_line(t_map *m, int *line, int clr)
{
	float	s;
	int		temp;

	s = (float)(line[3] - line[2]) / (line[1] - line[0]);
	if ((line[3] - line[2] < 0 && fabsf(s) > 1) ||
			(line[1] - line[0] < 0 && fabsf(s) < 1))
	{
		temp = line[3];
		line[3] = line[2];
		line[2] = temp;
		temp = line[1];
		line[1] = line[0];
		line[0] = temp;
	}
	if (line[0] == line[1])
	{
		while (line[2] < line[3])
			mlx_pixel_put(m->mlx, m->win, line[0], line[2]++, C(clr, m->c));
		return ;
	}
	if (line[3] - line[2] < line[1] - line[0])
		small_slope(m, line, s, clr);
	else
		big_slope(m, line, s, clr);
	free(line);
}

void		draw_map(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->row)
	{
		j = 0;
		while (++j < m->col + 1)
		{
			if (j < m->col)
				draw_line(m, new_line(X(i, j, m->xb, m->h),
					X(i, (j + 1), m->xb, m->h),
					Y(i, j, m->yb, m->v - m->val[i][j - 1] * m->m),
					Y(i, (j + 1), m->yb, m->v - m->val[i][j] * m->m)),
					m->val[i][j] + m->val[i][j - 1]);
			if (i < m->row - 1)
				draw_line(m, new_line(X(i, j, m->xb, m->h),
					X((i + 1), j, m->xb, m->h),
					Y(i, j, m->yb, m->v - m->val[i][j - 1] * m->m),
					Y(i, (j + 1), m->yb, m->v - m->val[i + 1][j - 1] * m->m)),
					m->val[i][j - 1] + m->val[i + 1][j - 1]);
		}
	}
}
