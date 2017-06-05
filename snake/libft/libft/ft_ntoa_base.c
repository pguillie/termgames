/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:50:43 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 16:52:10 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ntoa_base(long long nb, int base)
{
	char	*s;
	int		len;

	if (nb == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	len = ft_nblen_base(nb, base);
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (nb < 0)
		s[0] = '-';
	nb < 0 ? nb = -nb : 0;
	if (nb == 0)
	{
		s[0] = '0';
		s[1] = 0;
		return (s);
	}
	while (nb)
	{
		s[--len] = nb % base > 9 ? nb % base - 10 + 'a' : nb % base + '0';
		nb /= base;
	}
	return (s);
}
