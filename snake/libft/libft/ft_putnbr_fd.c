/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:17:57 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:17:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	long	pow;

	if (n < 0)
		ft_putchar_fd('-', fd);
	nb = n > 0 ? (long)n : -(long)n;
	pow = 1;
	while (pow * 10 <= nb)
		pow *= 10;
	while (pow > 0)
	{
		ft_putchar_fd((nb - nb / (pow * 10) * pow * 10) / pow + '0', fd);
		pow /= 10;
	}
}
