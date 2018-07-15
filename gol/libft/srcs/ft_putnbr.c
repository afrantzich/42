/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:36:36 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/17 15:24:42 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	crunch(int n)
{
	int temp;

	temp = n % 10;
	if (n >= 10 || n <= -10)
		crunch(n / 10);
	if (n < 0)
		ft_putchar((temp * -1) + '0');
	else
		ft_putchar(temp + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	crunch(n);
}
