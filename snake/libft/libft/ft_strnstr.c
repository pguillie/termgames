/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:28:16 by pguillie          #+#    #+#             */
/*   Updated: 2016/11/11 12:27:52 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	len;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	len = ft_strlen(needle);
	while (haystack[i] && i < n && len <= n - i)
	{
		if (!(ft_strncmp(haystack + i, needle, len)))
			return ((char*)(haystack + i));
		i++;
	}
	return (NULL);
}
