/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:25:20 by pguillie          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_inttabnew(size_t size)
{
	int		*tab;
	size_t	i;

	if (!(tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		tab[i++] = 0;
	return (tab);
}
