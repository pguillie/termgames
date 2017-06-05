/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 12:54:40 by pguillie          #+#    #+#             */
/*   Updated: 2016/12/14 12:50:03 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *body, char *part, size_t pos)
{
	char	*save;
	char	*tmp;

	if (!(save = ft_strdup(body + pos)))
		return (NULL);
	tmp = body;
	body = ft_strnew(ft_strlen(body) + 1);
	body = ft_strcpy(body, tmp);
	free(tmp);
	ft_strclr(body + pos);
	ft_strcat(ft_strcat(body, part), save);
	free(save);
	return (body);
}
