/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 22:32:10 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/20 11:19:49 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		if (*(unsigned char*)(dst - 1) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
