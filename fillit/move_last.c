/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:44:50 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 12:52:39 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	reset(char **board, int pnum)
{
	int sym;
	int i;
	int j;

	sym = 0;
	i = -1;
	while (board[++i])
	{
		j = -1;
		while (board[i][++j])
		{
			if (board[i][j] == 65 + pnum)
			{
				board[i][j] = '.';
				if (++sym == 1)
				{
					g_row = i;
					g_col = j + 1;
				}
			}
			if (sym == 4)
				return ;
		}
	}
}

void		move_last(int pnum, char **board)
{
	if (pnum < 0)
	{
		board = grow(board);
		g_row = 0;
		g_col = 0;
		return ;
	}
	reset(board, pnum);
}
