/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrantzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:03:53 by afrantzi          #+#    #+#             */
/*   Updated: 2018/04/23 16:47:38 by afrantzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*content_copy;
	size_t	size_copy;
	t_list	*new;

	if (NULL == (new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	content_copy = (void*)content;
	size_copy = content_size;
	if (!content_copy)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = ft_memalloc(size_copy);
		new->content = ft_memcpy(new->content, content_copy, size_copy);
		new->content_size = size_copy;
	}
	new->next = NULL;
	return (new);
}
