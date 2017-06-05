/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:48:01 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/08 10:54:49 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*new;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	if (!(new = (char*)malloc(i + 1)))
		return (NULL);
	new[i] = '\0';
	while (i--)
		new[i] = str[i];
	return (new);
}
