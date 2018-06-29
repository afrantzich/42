/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:43 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/23 15:21:36 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}