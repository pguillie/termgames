/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:05:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 16:10:23 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getstr(va_list ap, int n)
{
	char	*ret;

	while (--n)
		va_arg(ap, void*);
	ret = ft_untoa_base(va_arg(ap, unsigned long), 16);
	if (!ret)
		ret = ft_strnew(1);
	return (ret);
}

static char	*ft_shape(char *s, int *space, char *f, int len)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(len + space[0] + space[1])))
		return (NULL);
	i = 0;
	if (f[0] != '-')
	{
		while (space[1]--)
			ret[i++] = ' ';
	}
	ret[i++] = '0';
	ret[i++] = f[4] == '/' ? 'X' : 'x';
	while (space[0]--)
		ret[i++] = '0';
	if (f[4] == '/')
		s = ft_strupper(s);
	while (*s)
		ret[i++] = *s++;
	while (space[1]-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_ptr(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		space[2];
	int		len;

	if (!(s = ft_getstr(ap, f.param)) || (!f.prec && *s == '0'))
		*s = '\0';
	space[0] = 0;
	space[1] = 0;
	len = ft_strlen(s);
	if (f.prec > 0 && f.prec > len)
		space[0] = f.prec - len;
	len += 2;
	if (f.width > len + space[0])
	{
		if (f.flags[2] == '0' && f.prec < 0 && f.flags[0] != '-')
			space[0] = f.width - len;
		else
			space[1] = f.width - len - space[0];
	}
	ret = ft_shape(s, space, f.flags, len);
	free(s);
	return (ret);
}
