/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:40:35 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/13 13:34:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*tmp;

	l = *alst;
	while (l)
	{
		tmp = l;
		del(l->content, l->content_size);
		l = tmp->next;
		free(tmp);
	}
	*alst = NULL;
}
