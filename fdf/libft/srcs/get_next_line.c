/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 01:06:40 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/24 22:45:28 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

int	actually_get_next_line(char **save, char **line, int fd, char *temp)
{
	int i;

	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	if (!save[fd][0])
		return (0);
	*line = ft_strsub(save[fd], 0, i);
	temp = save[fd];
	save[fd] = ft_strsub(save[fd], i + 1, ft_strlen(save[fd]) - i);
	free(temp);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char **save;
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (!save)
		save = (char**)malloc(sizeof(char*) * 4900);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save[fd])
		{
			temp = save[fd];
			save[fd] = ft_strjoin(save[fd], buf);
			free(temp);
		}
		else
			save[fd] = ft_strdup((const char*)buf);
	}
	if (ret < 0)
		return (-1);
	return (actually_get_next_line(save, line, fd, temp));
}
