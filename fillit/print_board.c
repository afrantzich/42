/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 17:50:09 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/02 17:37:44 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(char **board)
{
	int i;
	int j;

	i = -1;
	while (++i < g_size)
	{
		j = 0;
		while (j < g_size)
			write(1, &board[i][j++], 1);
		write(1, "\n", 1);
	}
}
