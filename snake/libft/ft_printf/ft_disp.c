/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:38:16 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 16:29:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_disp(t_strout *s)
{
	int			ret;
	t_strout	*tmp;

	ret = 0;
	while (s)
	{
		write(1, s->str, s->len);
		ret += s->len;
		tmp = s->next;
		free(s->f.flags);
		free(s->str);
		free(s);
		s = tmp;
	}
	return (ret);
}
