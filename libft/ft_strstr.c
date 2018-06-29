/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 20:00:26 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/17 13:52:56 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		if (*haystack == *needle &&
				!(ft_strncmp(haystack, needle, ft_strlen(needle))))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
