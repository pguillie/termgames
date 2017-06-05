/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unblen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:59:11 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 18:29:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unblen_base(unsigned long long n, int base)
{
	int			len;
	long double	pow;

	pow = 1;
	len = 0;
	while (n >= (pow *= base))
		len++;
	return (len + 1);
}
