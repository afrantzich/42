/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:13:00 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 17:24:23 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack && ft_strlen(needle) <= len && len--)
	{
		if (*haystack == *needle &&
				!(ft_strncmp(haystack, needle, ft_strlen(needle))))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
