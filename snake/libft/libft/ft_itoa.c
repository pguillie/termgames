/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:13:01 by pguillie          #+#    #+#             */
/*   Updated: 2016/12/09 12:33:17 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	long long	l;
	int			i;

	i = ft_intlen(n);
	if (!(s = ft_strnew(i)))
		return (NULL);
	l = (long long)n;
	if (n < 0)
		s[0] = '-';
	if (!l)
		s[0] = '0';
	while (l)
	{
		s[--i] = ABS(l) % 10 + '0';
		l = l / 10;
	}
	return (s);
}
