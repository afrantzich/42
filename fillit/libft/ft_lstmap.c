/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:30:03 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/21 22:58:15 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (lst != NULL && f != NULL)
	{
		list = f(lst);
		if (list != NULL || lst->next != NULL)
			list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
