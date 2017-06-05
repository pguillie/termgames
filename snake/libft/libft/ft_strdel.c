/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:12:23 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/28 19:15:25 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	size_t	i;

	if (as)
	{
		i = 0;
		while ((*as)[i])
			(*as)[i++] = '\0';
		free(*as);
		*as = NULL;
	}
}
