/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:47:09 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 17:01:38 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**fill(char const *s, char c, char **split, size_t words)
{
	size_t			i;
	size_t			j;
	size_t			word;
	unsigned int	start;

	i = 0;
	j = -1;
	while (++j < words)
	{
		word = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i++] != c)
			word++;
		split[j] = ft_strsub(s, start, word);
	}
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t			words;
	char			**split;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (NULL == (split = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	split[words] = NULL;
	return (fill(s, c, split, words));
}
