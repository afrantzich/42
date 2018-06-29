/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 10:30:57 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/22 13:23:52 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (len == 0 || dst == src)
		return (dst);
	if (src < dst)
	{
		src = src + len - 1;
		dst = dst + len - 1;
		while (len--)
			*(unsigned char*)dst-- = *(unsigned char*)src--;
		return (dst + 1);
	}
	else
	{
		i = 0;
		while (i++ < len)
			*(unsigned char*)dst++ = *(unsigned char*)src++;
		return (dst - len);
	}
}
