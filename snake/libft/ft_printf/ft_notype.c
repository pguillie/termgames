/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_notype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:26:12 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 14:07:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_shape(char c, int space, int zero, char *f)
{
	char	*s;
	int		i;

	if (!(s = ft_strnew(space + zero + 1)))
		return (NULL);
	i = 0;
	while (zero--)
		s[i++] = '0';
	if (f[0] == '-')
		s[i++] = c;
	while (space--)
		s[i++] = ' ';
	if (f[0] != '-')
		s[i++] = c;
	return (s);
}

t_strout	*ft_notype(t_strout *l)
{
	int		space;
	int		zero;
	char	c;

	c = l->str[l->len - 1];
	free(l->str);
	space = 0;
	zero = 0;
	l->len = l->f.width ? l->f.width : 1;
	if (l->f.width > 1)
	{
		if (l->f.flags[2] == '0' && l->f.flags[0] != '-')
			zero = l->f.width - 1;
		else
			space = l->f.width - 1;
	}
	l->str = ft_shape(c, space, zero, l->f.flags);
	return (l);
}
