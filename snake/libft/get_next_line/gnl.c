/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:15:19 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/16 17:46:56 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_gnl	g;

	if (!line || fd < 0 || fd >= 500)
		return (-1);
	!g.str[fd] ? g.str[fd] = ft_strnew(BUFF_SIZE) : 0;
	while ((g.i = ft_indexchr(g.str[fd], '\n')) < 0)
	{
		read(fd, g.buff, BUFF_SIZE);
		if ((g.ret = read(fd, g.buff, BUFF_SIZE)) <= 0)
		{
			*g.str[fd] ? *line = ft_strdup(g.str[fd]) : 0;
			*g.str[fd] ? g.i = 0 : 0;
			!g.ret ? ft_strdel(&g.str[fd]) : 0;
			return (g.i < 0 ? g.ret : 1);
		}
		g.tmp = g.str[fd];
		g.str[fd] = ft_strjoin(g.str[fd], g.buff);
		ft_strdel(&g.tmp);
		ft_strclr(g.buff);
	}
	*line = ft_strndup(g.str[fd], g.i);
	g.tmp = g.str[fd];
	g.str[fd] = ft_strdup(g.str[fd] + g.i + 1);
	ft_strdel(&g.tmp);
	return (1);
}
