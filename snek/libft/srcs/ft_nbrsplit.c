/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:19:49 by afrantzi          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:06 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	*fill(char const *s, char c, int *split, size_t words)
{
	size_t	i;
	int		j;
	char	*temp;

	i = -1;
	temp = (char*)s;
	while (++i < words)
	{
		j = 0;
		split[i] = ft_atoi((char*)(temp + j));
		while (temp[j] == c)
			j++;
		temp = strchr(temp + j, c);
	}
	return (split);
}

int			*ft_nbrsplit(char const *s, char c)
{
	size_t	words;
	int		*split;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (NULL == (split = (int*)malloc(sizeof(int) * words)))
		return (NULL);
	return (fill(s, c, split, words));
}
