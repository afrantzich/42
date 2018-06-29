/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:42:12 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 18:19:44 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_piece(const int *piece, char **board, int pnum)
{
	int i;
	int	cbuf;
	int rbuf;

	i = 0;
	cbuf = 0;
	rbuf = 0;
	board[g_row][g_col] = 65 + pnum;
	while (++i < 4)
	{
		if (piece[i] > piece[i - 1])
			cbuf++;
		else
		{
			cbuf = piece[i] - piece[0];
			rbuf++;
		}
		board[g_row + rbuf][g_col + cbuf] = 65 + pnum;
	}
}
