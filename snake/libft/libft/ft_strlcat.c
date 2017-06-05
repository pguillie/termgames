/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:25:37 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/11 10:49:05 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	if (!(n))
		return (lens);
	if (lend > n)
		return (n + lens);
	i = lend;
	j = 0;
	while (src[j] && i < n - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (lend + lens);
}
