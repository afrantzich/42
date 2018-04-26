/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:15:30 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 15:54:36 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprime(unsigned int n)
{
	unsigned int check;

	check = 2;
	if (check == 1 || check == 0)
		return (0);
	while (check <= n / 2)
	{
		if (n % check++ == 0)
			return (0);
	}
	return (1);
}
