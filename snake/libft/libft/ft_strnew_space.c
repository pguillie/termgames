/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:05:49 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:18:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew_space(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}
