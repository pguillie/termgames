/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:35:31 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 18:51:33 by pguillie         ###   ########.fr       */
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
		ret = ft_ntoa_base(va_arg(ap, int), 10);
	else if (len == 1)
		ret = ft_ntoa_base((char)va_arg(ap, int), 10);
	else if (len == 2)
		ret = ft_ntoa_base((short)va_arg(ap, int), 10);
	else if (len == 3)
		ret = ft_ntoa_base(va_arg(ap, size_t), 10);
	else if (len == 4)
		ret = ft_ntoa_base(va_arg(ap, long), 10);
	else if (len == 5)
		ret = ft_ntoa_base(va_arg(ap, long long), 10);
	else if (len == 6)
		ret = ft_ntoa_base(va_arg(ap, intmax_t), 10);
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
	if (f[1])
		ret[i++] = f[1];
	if (*s == '-')
		ret[i++] = *s++;
	while (space[0]--)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	while (space[1]-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_int(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		space[2];
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)) || (!f.prec && *s == '0'))
		*s = 0;
	space[0] = 0;
	space[1] = 0;
	len = ft_strlen(s);
	*s == '-' ? f.flags[1] = 0 : 0;
	if (f.flags[1] == '+' || f.flags[1] == ' ')
		len++;
	if (f.prec > 0 && f.prec > len - (f.flags[1] || *s == '-' ? 1 : 0))
		space[0] = f.prec - len + (f.flags[1] || *s == '-' ? 1 : 0);
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
