/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:20:21 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 17:14:24 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	crunch(int n)
{
	int temp;

	temp = n % 10;
	if (n == 0)
		return ('-');
	else if (n < 0)
		return ((temp * -1) + '0');
	else
		return (temp + '0');
}

char		*ft_itoa(int n)
{
	int		digits;
	char	*s;

	digits = ft_nbrlen(n) + 1;
	if (NULL == (s = (char*)malloc(sizeof(char) * digits)))
		return (NULL);
	s[digits] = '\0';
	if (n == 0)
	{
		s[0] = '0';
		return (s);
	}
	while (--digits >= 0)
	{
		s[digits] = crunch(n);
		n /= 10;
	}
	return (s);
}
