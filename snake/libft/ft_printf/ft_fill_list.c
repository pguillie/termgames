/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:13:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 13:39:41 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_strout		*ft_fill_list(t_strout *start, va_list ap)
{
	t_strout	*list;
	va_list		cpy;

	list = start;
	while (list)
	{
		if (list->f.type > 0)
		{
			va_copy(cpy, ap);
			list->str = ft_conversion(list->f, cpy, &list->len);
			va_end(cpy);
		}
		else if (list->f.type == -1)
			list = ft_notype(list);
		else if (list->f.type <= -10)
			list->str = ft_color(list->f.type);
		!list->len ? list->len = ft_strlen(list->str) : 0;
		list = list->next;
	}
	return (start);
}
