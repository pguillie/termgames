/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 12:56:34 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 18:27:40 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nblen_base(long long n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	if (n < 0)
		len++;
	n < 0 ? n = -n : 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}
