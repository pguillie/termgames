/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 10:39:07 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 10:41:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_tag(const char *s, t_fields *f)
{
	int		l;

	l = 1;
	while (s[l] && s[l] != '%' && s[l] != '{' && s[l] != '}')
		l++;
	if (s[l] != '}')
		return (l);
	if (ft_strnequ(s + 1, "black", MAX(l - 1, 5)))
		f->type = -10;
	else if (ft_strnequ(s + 1, "red", MAX(l - 1, 3)))
		f->type = -11;
	else if (ft_strnequ(s + 1, "green", MAX(l - 1, 5)))
		f->type = -12;
	else if (ft_strnequ(s + 1, "yellow", MAX(l - 1, 6)))
		f->type = -13;
	else if (ft_strnequ(s + 1, "blue", MAX(l - 1, 4)))
		f->type = -14;
	else if (ft_strnequ(s + 1, "magenta", MAX(l - 1, 7)))
		f->type = -15;
	else if (ft_strnequ(s + 1, "cyan", MAX(l - 1, 4)))
		f->type = -16;
	else if (ft_strnequ(s + 1, "white", MAX(l - 1, 5)))
		f->type = -17;
	ft_strnequ(s + 1, "eoc", l - 1) ? f->type = -18 : 0;
	return (l + 1);
}

char		*ft_color(char c)
{
	char	*s;

	if (c == -10)
		s = ft_strdup("\033[30m");
	if (c == -11)
		s = ft_strdup("\033[31m");
	if (c == -12)
		s = ft_strdup("\033[32m");
	if (c == -13)
		s = ft_strdup("\033[33m");
	if (c == -14)
		s = ft_strdup("\033[34m");
	if (c == -15)
		s = ft_strdup("\033[35m");
	if (c == -16)
		s = ft_strdup("\033[36m");
	if (c == -17)
		s = ft_strdup("\033[37m");
	if (c == -18)
		s = ft_strdup("\033[0m");
	return (s);
}
