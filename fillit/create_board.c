/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 18:25:29 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/05 13:04:34 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_board(void)
{
	int		i;
	int		j;
	char	**board;

	while (g_size * g_size < g_pieces * 4)
		g_size++;
	if (NULL == (board = (char**)malloc(sizeof(char*) * (g_size + 3))))
		return (NULL);
	board[g_size + 2] = NULL;
	i = -1;
	while (++i < g_size + 2)
	{
		j = 0;
		board[i] = ft_memalloc(g_size + 3);
		while (j < g_size && i < g_size)
			board[i][j++] = '.';
	}
	return (board);
}
