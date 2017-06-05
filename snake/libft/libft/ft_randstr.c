/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_randstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:21:13 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/07 15:40:28 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_randstr(size_t len)
{
	char	*str;
	size_t	i;

	if (!(str = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = rand();
	return (str);
}
