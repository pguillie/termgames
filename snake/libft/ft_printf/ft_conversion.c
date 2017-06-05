/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:52:45 by pguillie          #+#    #+#             */
/*   Updated: 2017/01/31 12:30:42 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_conversion(t_fields f, va_list ap, int *list_len)
{
	if (f.type == 'd' || f.type == 'i')
		return (ft_int(ap, f));
	else if (f.type == 'u')
		return (ft_unsint(ap, f));
	else if (f.type == 'x')
		return (ft_hexa(ap, f));
	else if (f.type == 'o')
		return (ft_octal(ap, f));
	else if (f.type == 's')
		return (ft_string(ap, f));
	else if (f.type == 'c')
		return (ft_char(ap, f, list_len));
	else if (f.type == 'p')
		return (ft_ptr(ap, f));
	else if (f.type == 'b')
		return (ft_bin(ap, f));
	else if (f.type == '%')
		return (ft_percent(f));
	return (NULL);
}
