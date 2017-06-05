/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:17:06 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 15:59:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_percent(t_fields f)
{
	char	*ret;
	int		space;
	int		i;

	space = 0;
	if (f.width)
		space = f.width - 1;
	if (!(ret = ft_strnew(space + 1)))
		return (NULL);
	i = 0;
	if (f.flags[2] != '0')
		f.flags[2] = ' ';
	if (f.flags[0] != '-')
	{
		while (space--)
			ret[i++] = f.flags[2];
	}
	ret[i++] = '%';
	while (space-- > 0)
		ret[i++] = ' ';
	return (ret);
}
