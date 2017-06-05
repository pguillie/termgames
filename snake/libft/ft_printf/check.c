/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:23:09 by pguillie          #+#    #+#             */
/*   Updated: 2017/02/01 17:19:58 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_istype(t_fields *f, char c)
{
	if (c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'x' || c == 'c' || c == 'b' || c == 'v' || c == '%')
		return (c);
	if (c == 'S' || c == 'D' || c == 'O' || c == 'U' || c == 'C')
	{
		if (f->length < 4)
			f->length = 4;
		return (c - 'A' + 'a');
	}
	else if (c == 'X')
	{
		f->flags[4] = '/';
		return ('x');
	}
	return (0);
}

int		ft_flags(t_fields *f, char c)
{
	if (c == '-')
		f->flags[0] = '-';
	else if (c == '+')
		f->flags[1] = '+';
	else if (c == ' ')
		f->flags[1] != '+' ? f->flags[1] = ' ' : 0;
	else if (c == '0')
		f->flags[2] = '0';
	else if (c == '#')
		f->flags[3] = '#';
	else if (c == '/')
		f->flags[4] = '/';
	else if (c == '|')
		f->flags[4] != '/' ? f->flags[4] = '|' : 0;
	else
		return (0);
	return (1);
}

int		ft_precision(t_fields *f, const char *s)
{
	int		n;
	int		ret;

	n = 0;
	ret = 0;
	while (s[ret] >= '0' && s[ret] <= '9')
		n = n * 10 + s[ret++] - '0';
	f->prec = n;
	return (ret + 1);
}

int		ft_length(t_fields *f, char a, char b)
{
	int		c;

	if (a == 'h')
	{
		c = 1;
		b != 'h' ? c += 1 : 0;
	}
	else if (a == 'z')
		c = 3;
	else if (a == 'l')
	{
		c = 4;
		b == 'l' ? c += 1 : 0;
	}
	else if (a == 'j')
		c = 6;
	else
		return (-1);
	c > f->length ? f->length = c : 0;
	return ((c == 1 || c == 5) ? 2 : 1);
}

int		ft_par_wid(t_fields *f, const char *s)
{
	int		l;
	int		n;

	n = 0;
	l = 0;
	while (s[l] >= '0' && s[l] <= '9')
		n = n * 10 + s[l++] - '0';
	if (!n)
		return (-1);
	if (s[l] == '$')
	{
		f->param = n;
		l++;
	}
	else
		f->width = n;
	return (l);
}
