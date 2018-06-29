/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_empty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:16:33 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 13:01:57 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	next_empty(int **piece, int pnum, char **board)
{
	while (g_row < g_size)
	{
		if (++g_col >= g_size)
		{
			g_col = 0;
			g_row++;
		}
		if (board[g_row][g_col] == '.' && check_dimensions(piece[pnum])
				&& can_fit(piece[pnum], (const char**)board))
			return (0);
	}
	move_last(--pnum, board);
	if (pnum < 0)
		return (0);
	else
		return (1);
}
