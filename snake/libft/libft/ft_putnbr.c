/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:30:37 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:17:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	nb;
	long	pow;

	if (n < 0)
		ft_putchar('-');
	nb = n > 0 ? (long)n : -(long)n;
	pow = 1;
	while (pow * 10 <= nb)
		pow *= 10;
	while (pow > 0)
	{
		ft_putchar((nb - nb / (pow * 10) * pow * 10) / pow + '0');
		pow /= 10;
	}
}
