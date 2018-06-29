/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:45:45 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 18:15:34 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	solve(int **piece, int pnum, char **board)
{
	while (pnum < g_pieces)
	{
		if (board[g_row][g_col] != '.' || !check_dimensions(piece[pnum]) ||
			!can_fit(piece[pnum], (const char**)board))
			pnum -= next_empty(piece, pnum, board);
		else
		{
			place_piece(piece[pnum], board, pnum);
			g_row = 0;
			g_col = 0;
			pnum++;
		}
	}
}
