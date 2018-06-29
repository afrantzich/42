/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:32:58 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/23 22:16:17 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*traverse;

	if (!alst || !del)
		return ;
	traverse = *alst;
	while (traverse)
	{
		del(traverse->content, traverse->content_size);
		ft_memdel((void**)alst);
		*alst = traverse->next;
		traverse = *alst;
	}
	*alst = NULL;
}
