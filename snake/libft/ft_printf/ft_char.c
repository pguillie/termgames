/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:16:57 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 16:05:02 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getstr(va_list ap, int len, int n)
{
	char	*s;

	while (--n)
		va_arg(ap, void*);
	if (len == 4)
		return (ft_wstruct(va_arg(ap, wint_t)));
	if (!(s = ft_strnew(1)))
		return (NULL);
	s[0] = (char)va_arg(ap, int);
	return (s);
}

static char	*ft_shape(char *s, int *space, char *f, int len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = ft_strnew(len + space[0] + space[1])))
		return (NULL);
	if (f[0] != '-')
	{
		while (space[1]--)
			ret[i++] = ' ';
	}
	while (space[0]--)
		ret[i++] = '0';
	if (f[5] == '|')
		s = ft_strlower(s);
	if (f[5] == '/')
		s = ft_strupper(s);
	while (*s)
		ret[i++] = *s++;
	while (space[1]-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_char(va_list ap, t_fields f, int *list_len)
{
	char	*s;
	char	*ret;
	int		space[2];
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)))
		*s = 0;
	space[0] = 0;
	space[1] = 0;
	len = ft_strlen(s);
	!len ? len = 1 : 0;
	if (f.width > len)
	{
		if (f.flags[2] == '0' && f.flags[0] != '-')
			space[0] = f.width - len;
		else
			space[1] = f.width - len;
	}
	*list_len = len + space[0] + space[1];
	ret = ft_shape(s, space, f.flags, len);
	free(s);
	return (ret);
}
