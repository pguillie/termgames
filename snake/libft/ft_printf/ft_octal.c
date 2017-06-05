/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:43:15 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/26 16:08:18 by pguillie         ###   ########.fr       */
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
		ret = ft_untoa_base(va_arg(ap, unsigned int), 8);
	else if (len == 1)
		ret = ft_untoa_base((unsigned char)va_arg(ap, int), 8);
	else if (len == 2)
		ret = ft_untoa_base((unsigned short)va_arg(ap, int), 8);
	else if (len == 3)
		ret = ft_untoa_base(va_arg(ap, size_t), 8);
	else if (len == 4)
		ret = ft_untoa_base(va_arg(ap, unsigned long), 8);
	else if (len == 5)
		ret = ft_untoa_base(va_arg(ap, unsigned long long), 8);
	else if (len == 6)
		ret = ft_untoa_base(va_arg(ap, intmax_t), 8);
	if (!ret)
		ret = ft_strnew(1);
	return (ret);
}

static char	*ft_shape(char *s, int *space, char *f, int len)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(len + space[0] + space[1] + space[2])))
		return (NULL);
	i = 0;
	if (f[0] != '-')
	{
		while (space[2]--)
			ret[i++] = ' ';
	}
	if (space[1])
		ret[i++] = '0';
	while (space[0]--)
		ret[i++] = '0';
	while (*s)
		ret[i++] = *s++;
	while (space[2]-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_octal(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		space[3];
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)) || (!f.prec && *s == '0'))
		*s = '\0';
	space[0] = 0;
	space[1] = 0;
	space[2] = 0;
	if (f.prec > (len = ft_strlen(s)))
		space[0] = f.prec - len;
	if (f.flags[3] == '#' && !space[0] && *s != '0')
		space[1]++;
	if (f.width > len + space[0] + space[1])
	{
		if (f.flags[2] == '0' && f.prec < 0 && f.flags[0] != '-')
			space[0] = f.width - len - space[1];
		else
			space[2] = f.width - len - space[0] - space[1];
	}
	ret = ft_shape(s, space, f.flags, len);
	free(s);
	return (ret);
}
