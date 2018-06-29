/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 10:29:01 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/22 13:46:18 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*trim;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[i] == 32 || s[i] == 10 || s[i] == 9)
		i++;
	while ((s[len] == 32 || s[len] == 10 || s[len] == 9) && len >= i)
		len--;
	len = len - i + 1;
	if (NULL == (trim = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	trim[len] = '\0';
	while (--len >= 0)
		trim[len] = s[len + i];
	return (trim);
}
