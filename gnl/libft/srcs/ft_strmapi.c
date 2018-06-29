/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:47:55 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/23 11:54:21 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new;
	size_t			len;
	size_t			j;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (NULL == (new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < len)
	{
		if (f(i, s[i]))
			new[j++] = f(i, s[i]);
	}
	new[j] = '\0';
	return (new);
}
