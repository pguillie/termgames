/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:46:34 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 11:40:37 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_getstr(va_list ap, int len, int n)
{
	char	*s;
	char	*r;
	wchar_t	*w;
	int		i[2];

	while (--n)
		va_arg(ap, void*);
	if (!(i[0] = 0) && len != 4)
		return (ft_strdup(va_arg(ap, char*)));
	if (!(w = va_arg(ap, wchar_t*)))
		return (NULL);
	while (w[i[0]])
		i[0]++;
	if (!(s = ft_strnew(i[0] * 4)))
		return (NULL);
	i[0] = 0;
	while (*w)
	{
		r = ft_wstruct(*w++);
		i[1] = 0;
		while (r[i[1]])
			s[i[0]++] = r[i[1]++];
		free(r);
	}
	return (s);
}

static char	*ft_shape(char *s, int space, char *f, int len)
{
	char	*ret;
	int		i;

	if (!(ret = ft_strnew(len + space)))
		return (NULL);
	i = 0;
	if (f[2] != '0')
		f[2] = ' ';
	if (f[0] != '-')
	{
		while (space--)
			ret[i++] = f[2];
	}
	if (f[4] == '|')
		s = ft_strlower(s);
	else if (f[4] == '/')
		s = ft_strupper(s);
	while (*s)
		ret[i++] = *s++;
	while (space-- > 0)
		ret[i++] = ' ';
	return (ret);
}

char		*ft_string(va_list ap, t_fields f)
{
	char	*s;
	char	*ret;
	int		space;
	int		len;

	if (!(s = ft_getstr(ap, f.length, f.param)))
		s = ft_strdup("(null)");
	space = 0;
	len = ft_strlen(s);
	if (f.prec >= 0 && f.prec < len)
	{
		while (!((unsigned char)s[f.prec] >> 6 ^ 2))
			f.prec--;
		s[f.prec] = '\0';
		len = f.prec;
	}
	if (f.width > len)
		space = f.width - len;
	ret = ft_shape(s, space, f.flags, len);
	free(s);
	return (ret);
}
