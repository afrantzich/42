/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:37:47 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 17:24:03 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	i;

	if (NULL == (mem = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i <= size)
		*(mem + i) = 0;
	return (mem);
}
