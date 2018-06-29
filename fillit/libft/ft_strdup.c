/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:47:33 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/18 00:10:18 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*key;
	size_t	i;

	i = ft_strlen(s1);
	if (!(key = (char *)malloc(sizeof(char) * i + 1)))
		return ((void*)0);
	ft_strcpy(key, s1);
	return (key);
}
