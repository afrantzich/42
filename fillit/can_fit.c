/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_fit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:40:29 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 12:14:45 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	can_fit(const int *piece, const char **board)
{
	int i;
	int	cbuf;
	int rbuf;

	i = 0;
	cbuf = 0;
	rbuf = 0;
	while (++i < 4)
	{
		if (piece[i] > piece[i - 1])
			cbuf++;
		else
		{
			cbuf = piece[i] - piece[0];
			rbuf++;
		}
		if (board[g_row + rbuf][g_col + cbuf] != '.')
			return (0);
	}
	return (1);
}
