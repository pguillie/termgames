/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:06:30 by pguillie          #+#    #+#             */
/*   Updated: 2017/05/23 17:39:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_error(char *m, char *s, char *g)
{
	if (m)
	{
		ft_putstr_fd(m, 2);
		if (s)
		{
			ft_putstr_fd(": ", 2);
			ft_putstr_fd(s, 2);
			if (g)
			{
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(g, 2);
			}
		}
		ft_putchar_fd('\n', 2);
		return (1);
	}
	return (-1);
}
