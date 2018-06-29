/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:08:09 by afrantzi          #+#    #+#             */
/*   Updated: 2018/05/20 15:20:16 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	if (NULL == (dup = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		dup[i] = s1[i];
	dup[i] = '\0';
	return (dup);
}
