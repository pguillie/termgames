/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:05:49 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:18:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewchr(size_t size, char c)
{
	char	*str;

	if (!(str = (char*)malloc(size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = c;
	return (str);
}
