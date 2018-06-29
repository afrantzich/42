/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:37:56 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/23 11:29:39 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len;

	if (s[0] == '\0')
		return (NULL);
	len = ft_strlen(s);
	if (c == '\0')
		return ((char*)(s + len));
	while (len--)
	{
		if (s[len] == c)
			return ((char*)(s + len));
	}
	return (NULL);
}
