/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:44:55 by pguillie          #+#    #+#             */
/*   Updated: 2017/03/06 16:31:00 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "libft.h"

# define MAX(x, y) (x > y ? x : y)

/*
** STRUCTURES
*/

typedef struct		s_fields
{
	int				param;
	char			*flags;
	int				width;
	int				prec;
	int				length;
	char			type;
}					t_fields;

typedef struct		s_strout
{
	t_fields		f;
	char			*str;
	int				len;
	int				num;
	struct s_strout	*next;
}					t_strout;

/*
** MAIN FUNCTIONS
*/

int					ft_printf(const char *format, ...);
t_strout			*ft_create_list(const char *str, t_strout *start);
t_strout			*ft_fill_list(t_strout *start, va_list ap);
char				*ft_conversion(t_fields f, va_list ap, int	*list_len);
int					ft_disp(t_strout *s);

/*
** ARGUMENTS
*/

int					ft_istype(t_fields *f, char c);
int					ft_flags(t_fields *f, char c);
int					ft_precision(t_fields *f, const char *s);
int					ft_length(t_fields *f, char a, char b);
int					ft_par_wid(t_fields *f, const char *s);

/*
** CONVERSIONS
*/

char				*ft_int(va_list ap, t_fields f);
char				*ft_unsint(va_list ap, t_fields f);
char				*ft_hexa(va_list ap, t_fields f);
char				*ft_octal(va_list ap, t_fields f);
char				*ft_string(va_list ap, t_fields f);
char				*ft_char(va_list ap, t_fields f, int *list_len);
char				*ft_ptr(va_list ap, t_fields f);
char				*ft_bin(va_list ap, t_fields f);
char				*ft_percent(t_fields f);

/*
** TOOLS
*/

char				*ft_color(char c);
t_strout			*ft_notype(t_strout *list);
char				*ft_wstruct(wint_t c);
int					ft_tag(const char *s, t_fields *f);

#endif
