/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:39:15 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 13:04:09 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_dimensions(const int *piece)
{
	int buf;
	int i;

	if ((piece[0] > 1 && g_col == 0) || (piece[0] == 3 && g_col == 1))
		return (0);
	buf = 0;
	i = 0;
	while (++i < 4)
	{
		if (piece[i] > piece[0] && g_col + (piece[i] - piece[0]) >= g_size)
			return (0);
		if (piece[i] <= piece[i - 1])
			buf++;
	}
	if (buf + g_row >= g_size)
		return (0);
	return (1);
}
