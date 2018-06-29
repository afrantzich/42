/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:59:36 by kradoste          #+#    #+#             */
/*   Updated: 2018/05/05 18:41:45 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_pieces = 0;
int	g_size = 2;
int	g_col = 0;
int	g_row = 0;

static int	error_checker(char *c, int x, int *size, int *nutt_term)
{
	if (c[x])
	{
		if (c[x] != '.' && c[x] != '\n' && c[x] != '#')
			return (0);
		else if (c[x] != '\n' && (x % 5 == 4 || x == 20))
			return (0);
		else if (c[x] != '.' && c[x] != '#' && x % 5 != 4 && x != 20)
			return (0);
		if (c[x] == '#')
			if (*size > (x % 5) + 1)
				*size = (x % 5) + 1;
	}
	else
	{
		if (x == 19)
			return (0);
		if (x == 20)
			*nutt_term = 1;
	}
	return (1);
}

static int	*valid_tetrimino(char *c, int *size, int *nutt_term)
{
	int		x;
	int		link;
	int		hash;
	int		*figure;

	figure = (int *)malloc(sizeof(int) * 5);
	figure[4] = 0;
	hash = 0;
	link = 0;
	x = -1;
	while (++x < 21)
		if (!error_checker(c, x, size, nutt_term))
			return (NULL);
		else if (c[x] == '#')
		{
			figure[hash++] = (x % 5) + 1;
			(c[x - 1] == '#') && (link += 1);
			(c[x + 1] == '#') && (link += 1);
			(c[x + 5] == '#') && (link += 1);
			(c[x - 5] == '#') && (link += 1);
		}
	if ((link != 6 && link != 8) || hash != 4)
		return (NULL);
	return (figure);
}

static int	**tetri_separator(char *filename, int **tetriminos, int *nutt_term)
{
	int		file;
	char	buf[21];
	int		size;
	int		y;

	file = open(filename, O_RDONLY);
	if (file < 0)
		return (NULL);
	g_pieces = 0;
	while (read(file, &buf, 21) && g_pieces < 26)
	{
		size = 4;
		y = 0;
		if (!(tetriminos[g_pieces] = valid_tetrimino(buf, &size, nutt_term)))
			return (NULL);
		while (y < 4)
			tetriminos[g_pieces][y++] -= (size - 1);
		ft_bzero(buf, 21);
		g_pieces++;
	}
	if (g_pieces == 26 || g_pieces == -1)
		return (NULL);
	close(file);
	return (tetriminos);
}

void		andrews_work(int **tetriminos)
{
	char	**board;
	int		x;

	x = 0;
	board = create_board();
	solve(tetriminos, 0, board);
	print_board(board);
	while (board[x])
		free(board[x++]);
	free(board);
	while (--g_pieces >= 0)
		free(tetriminos[g_pieces]);
	free(tetriminos);
}

int			main(int argc, char **argv)
{
	int		**tetriminos;
	int		x;
	int		nutt_term;

	if (argc == 1 || argc > 2)
		ft_putstr("usage: fillit input_file\n");
	else
	{
		tetriminos = (int **)malloc(sizeof(int *) * 26 + 1);
		x = -1;
		nutt_term = 0;
		while (tetriminos[++x])
			tetriminos[x] = malloc(sizeof(int) * 5);
		if (!(tetriminos = tetri_separator(argv[1], tetriminos,
&nutt_term)) || nutt_term != 1)
		{
			write(1, "error\n", 6);
			return (0);
		}
		andrews_work(tetriminos);
	}
	return (0);
}
