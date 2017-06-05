/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:00:46 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 16:31:38 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_strout	*ft_lst_new(char *s, size_t len, t_fields f)
{
	t_strout	*new;
	size_t		i;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	if (f.type <= 0 && f.type > -10)
	{
		i = 0;
		if (!(new->str = (char*)malloc(len)))
			return (NULL);
		while (i < len)
			new->str[i++] = *s++;
		new->len = len;
	}
	else
	{
		new->str = NULL;
		new->len = 0;
	}
	new->f = f;
	new->next = NULL;
	return (new);
}

static int		ft_fields(const char *s, t_fields *f)
{
	int			l;
	int			notype;
	int			n;

	notype = 0;
	n = -1;
	l = 1;
	while (!(f->type = ft_istype(f, s[l])) && !notype)
	{
		if (ft_flags(f, s[l]))
			l++;
		else if (s[l] == '.')
			l += ft_precision(f, s + l + 1);
		else if ((n = ft_length(f, s[l], s[l + 1])) >= 0)
			l += n;
		else if ((n = ft_par_wid(f, s + l)) >= 0)
			l += n;
		else
			notype++;
	}
	if (!s[l])
		f->type = 'v';
	else if (notype)
		f->type = -1;
	return (s[l] ? l + 1 : l);
}

static t_fields	*ft_init(t_fields *f)
{
	f->param = 0;
	if (!(f->flags = ft_strnew(5)))
		return (NULL);
	f->width = 0;
	f->prec = -1;
	f->length = 0;
	f->type = 0;
	return (f);
}

static int		ft_get(const char *s, int *p, t_fields *f)
{
	int		l;

	l = 0;
	while (s[l] && s[l] != '%' && s[l] != '{')
		l++;
	if (!(ft_init(f)))
		return (0);
	if (!l && s[l] == '{')
		l = ft_tag(s, f);
	else if (!l)
		l = ft_fields(s, f);
	if (f->type > 0 && f->type != '%' && !f->param)
	{
		f->param = *p;
		*p += 1;
	}
	return (l);
}

t_strout		*ft_create_list(const char *str, t_strout *start)
{
	t_strout	*list;
	t_fields	f;
	int			i;
	int			len;
	int			pos;

	i = 0;
	pos = 1;
	while (str[i])
	{
		if (!(len = ft_get(str + i, &pos, &f)))
			return (NULL);
		if (!start)
		{
			start = ft_lst_new((char*)str + i, len, f);
			list = start;
		}
		else
		{
			list->next = ft_lst_new((char*)str + i, len, f);
			list = list->next;
		}
		i += len;
	}
	return (start);
}
