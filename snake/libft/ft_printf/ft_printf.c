/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:27:12 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 16:31:50 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_strout	*start;
	int			ret;

	start = NULL;
	ret = 0;
	va_start(ap, format);
	start = ft_create_list(format, start);
	start = ft_fill_list(start, ap);
	va_end(ap);
	ret = ft_disp(start);
	return (ret);
}
