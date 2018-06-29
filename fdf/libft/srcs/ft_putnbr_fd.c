/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 14:40:38 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/19 20:55:47 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	crunch(int n, int fd)
{
	int temp;

	temp = n % 10;
	if (n >= 10 || n <= -10)
		crunch(n / 10, fd);
	if (n < 0)
		ft_putchar_fd(((temp * -1) + '0'), fd);
	else
		ft_putchar_fd((temp + '0'), fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	crunch(n, fd);
}
