/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:23:08 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 16:14:46 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getstr(va_list ap, int len, int n)
{
	char	*ret;

	while (--n)
		va_arg(ap, void*);
	ret = NULL;
	if (!len)
		ret = ft_untoa_base(va_arg(ap, unsigned int), 2);
	else if (len == 1)
		ret = ft_untoa_base((unsigned char)va_arg(ap, int), 2);
	else if (len == 2)
		ret = ft_untoa_base((unsigned short)va_arg(ap, int), 2);
	else if (len == 3)
		ret = ft_untoa_base(va_arg(ap, size_t), 2);
	else if (len == 4)
		ret = ft_untoa_base(va_arg(ap, unsigned long), 2);
	else if (len == 5)
		ret = ft_untoa_base(va_arg(ap, unsigned long long), 2);
	else if (len == 6)
		ret = ft_untoa_base(va_arg(ap, intmax_t), 2);
	if (!ret)
		ret = ft_strnew(1);
	return (ret);
}

static char	*ft_shape(char *s, int *space, int len, char *f)
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
	if (f[3] == '#' && *s != '0' && *s)
	{
		ret[i++] = '0';
		ret[i++] = f[4] == '/' ? 'B' : 'b';
	}
	while (space[0]--)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	while (space[1]-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_bin(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		space[2];
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)) || (!f.prec && *s == '0'))
		*s = '\0';
	space[0] = 0;
	space[1] = 0;
	len = ft_strlen(s);
	if (f.prec > 0 && f.prec > len)
		space[0] = f.prec - len;
	if (f.flags[3] == '#' && *s != '0' && *s)
		len += 2;
	if (f.width > len + space[0])
	{
		if (f.flags[2] == '0' && f.prec < 0 && f.flags[0] != '-')
			space[0] = f.width - len;
		else
			space[1] = f.width - len - space[0];
	}
	ret = ft_shape(s, space, len, f.flags);
	free(s);
	return (ret);
}
