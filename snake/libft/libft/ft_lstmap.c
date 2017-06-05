/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:41:29 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/13 14:45:30 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*previous;
	t_list	*begin;
	void	*content;
	size_t	size;

	begin = NULL;
	while (lst)
	{
		content = (f(lst))->content;
		size = (f(lst))->content_size;
		if (!(new = ft_lstnew(content, size)))
			return (NULL);
		if (!(begin))
		{
			if (!(begin = ft_lstnew(content, size)))
				return (NULL);
			new = begin;
			previous = new;
		}
		previous->next = new;
		previous = new;
		lst = lst->next;
	}
	return (begin);
}
