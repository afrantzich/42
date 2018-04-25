/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:17:10 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/24 17:27:17 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memswap(void *a, void *b)
{
	unsigned char temp;

	temp = *(unsigned char*)a;
	*(unsigned char*)a = *(unsigned char*)b;
	*(unsigned char*)b = temp;
}
