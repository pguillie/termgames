/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:00 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/16 17:46:26 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_append(char *str, int fd, int *eof)
{
	char	*buffer;
	char	*tmp;
	int		ret;
	int		t;

	t = 0;
	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (NULL);
	while (!t || !(ft_strchr(str, '\n') || *eof))
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (NULL);
		t = 1;
		if (ret < BUFF_SIZE)
			*eof = 1;
		tmp = str;
		str = ft_strjoin(str, buffer);
		ft_strdel(&tmp);
		ft_strclr(buffer);
	}
	free(buffer);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	int				i;
	int				eof;

	i = 0;
	eof = 0;
	if (fd < 0 || !line || (str ? 0 : !(str = ft_strnew(BUFF_SIZE))))
		return (-1);
	if ((str = ft_append(str, fd, &eof)) == NULL)
		return (-1);
	if (str[0] == '\0' && eof)
	{
		ft_strdel(&str);
		free(str);
		return (0);
	}
	while (str[i] && str[i] != '\n')
		i++;
	*line = ft_strsub(str, 0, i);
	ft_memmove(str, str + i + 1, ft_strlen(str) - (i > 0 ? 1 : 0));
	return (1);
}
