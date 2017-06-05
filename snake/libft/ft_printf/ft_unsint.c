/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:49:38 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 16:14:12 by pguillie         ###   ########.fr       */
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
		ret = ft_untoa_base(va_arg(ap, unsigned int), 10);
	else if (len == 1)
		ret = ft_untoa_base((unsigned char)va_arg(ap, int), 10);
	else if (len == 2)
		ret = ft_untoa_base((unsigned short)va_arg(ap, int), 10);
	else if (len == 3)
		ret = ft_untoa_base(va_arg(ap, size_t), 10);
	else if (len == 4)
		ret = ft_untoa_base(va_arg(ap, unsigned long), 10);
	else if (len == 5)
		ret = ft_untoa_base(va_arg(ap, unsigned long long), 10);
	else if (len == 6)
		ret = ft_untoa_base(va_arg(ap, intmax_t), 10);
	if (!ret)
		ret = ft_strnew(1);
	return (ret);
}

static char	*ft_shape(char *s, int zero, int space, char *f)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(ft_strlen(s) + zero + space)))
		return (NULL);
	i = 0;
	if (f[0] != '-')
	{
		while (space--)
			ret[i++] = ' ';
	}
	while (zero--)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	while (space-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_unsint(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		zero;
	int		space;
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)) || (!f.prec && *s == '0'))
		*s = 0;
	zero = 0;
	space = 0;
	len = ft_strlen(s);
	if (f.prec > len)
		zero = f.prec - len;
	if (f.width > len + zero)
	{
		if (f.flags[2] == '0' && !zero && f.flags[0] != '-')
			zero = f.width - len;
		else
			space = f.width - len - zero;
	}
	ret = ft_shape(s, zero, space, f.flags);
	free(s);
	return (ret);
}
