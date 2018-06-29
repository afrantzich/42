/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 19:29:01 by kradoste          #+#    #+#             */
/*   Updated: 2018/05/05 17:31:46 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

extern int	g_pieces;
extern int g_col;
extern int g_row;
extern int g_size;

void	solve(int **piece, int pnum, char **board);
void	print_board(char **board);
void	place_piece(const int *piece, char **board, int pnum);
int		next_empty(int **piece, int pnum, char **board);
void	move_last(int pnum, char **board);
char	**grow(char **board);
char	**create_board(void);
int		check_dimensions(const int *piece);
int		can_fit(const int *piece, const char **board);

#endif
