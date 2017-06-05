/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:46:21 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:18:06 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *base, char const *to_app, char side)
{
	char	*new;
	char	*tmp;

	if (!(new = ft_strnew(ft_strlen(base) + ft_strlen(to_app))))
		return (NULL);
	tmp = base;
	if (side == 'l')
	{
		base = ft_strjoin(to_app, base);
		free(tmp);
		return (base);
	}
	if (side == 'r')
	{
		base = ft_strjoin(base, to_app);
		free(base);
		return (base);
	}
	return (base);
}
