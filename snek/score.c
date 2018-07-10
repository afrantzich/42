/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:16:11 by afrantzi          #+#    #+#             */
/*   Updated: 2018/07/10 16:23:39 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snek.h"
#include <fcntl.h>

char	***get_scores(int fd)
{
	char	*line;
	char ***scores;
	int		count;

	scores = (char ***)malloc(sizeof(char **) * 10);
	if ((fd = open("high_scores.txt", O_RDWR)) < 0)
		return (NULL);
	count = -1;
	while (get_next_line(fd, &line) > 0 && ++count < 10)
	{
		scores[count] = ft_strsplit(line, ' ');
		free(line);
	}
	return (scores);
}

void	print_scores(t_map *m, char ***scores)
{
	int		count;
	int		i;
	char	*line;

	mlx_string_put(m->mlx, m->win, WIDTH / 2 - 50, 50, 0x0000ff,
			"GAME OVER");
	mlx_string_put(m->mlx, m->win, WIDTH / 2 - 60, 250, 0x0000ff,
			"High Scores:");
	count = -1;
	while (++count < 10)
	{
		i = -1;
		while (++i < 3)
			mlx_string_put(m->mlx, m->win, WIDTH / 2 - 110 + i * i * 50,
					300 + count * 25, 0x0000ff, scores[count][i]);
	}
	line = ft_strjoin("Your Score: ", ft_itoa(m->len));
	mlx_string_put(m->mlx, m->win, WIDTH / 2 - 75, 600, 0x0000ff, line);
	free(line);
}

int		check_new_high_score(t_map *m, char ***scores)
{
	int count;

	count = -1;
	while (++count < 10)
	{
		if (ft_atoi(scores[count][2]) <= m->len)
			return (count);
	}
	return (0);
}

void	enter_name(t_map *m, int fd, int place, char ***scores)
{
	//implement later... for now, 'player' is the default name
	int i;
	int j;

	i = -1;
	while (++i < place)
	{
		j = -1;
		while (++j < 3)
		{
			ft_putstr_fd(scores[i][j], fd);
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
	}
	ft_putnbr_fd(place + 1, fd);
	ft_putstr_fd(". player ", fd);
	ft_putnbr_fd(m->len, fd);
	ft_putchar_fd('\n', fd);
	while (++i < 10)
	{
		j = 0;
		ft_putnbr_fd(ft_atoi(scores[i - 1][0]) + 1, fd);
		ft_putstr_fd(". ", fd);
		while (++j < 3)
		{
			ft_putstr_fd(scores[i - 1][j], fd);
			ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
	}
	close(fd);
}

void	free_scores(char ***scores)
{
	int i;
	int j;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 3)
			free(scores[i][j]);
		free(scores[i]);
	}
	free(scores);
}

void	score_screen(t_map *m)
{
	int		fd;
	int		place;
	char	***scores;

	if ((fd = open("high_scores.txt", O_RDWR)) < 0)
		return ;
	scores = get_scores(fd);
	if ((place = check_new_high_score(m, scores)) > 0)
	{
		enter_name(m, fd, place, scores);
		mlx_string_put(m->mlx, m->win, WIDTH / 2 - 80, 575, 0x0000ff, "New High Score!");
		free_scores(scores);
		if ((fd = open("high_scores.txt", O_RDWR)) < 0)
			return ;
		scores = get_scores(fd);
	}
	print_scores(m, scores);
	free_scores(scores);
	m->game_over = 2;
}
