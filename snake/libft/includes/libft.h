/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:04:11 by pguillie          #+#    #+#             */
/*   Updated: 2017/05/23 17:37:14 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "error_msg.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define OPT_SIZE 64
# define ABS(x) (x > 0 ? x : -x)
# define MIN(x, y) (x < y ? x : y)
# define MAX(x, y) (x > y ? x : y)

/*
** Structure
*/

typedef struct termios t_termios;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Booleen
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);

/*
** Display
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_error(char *m, char *s, char *g);

/*
** Memory
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);

/*
** String
*/

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				ft_striter(char *str, void (*f)(char*));
void				ft_striteri(char *str, void (*f)(unsigned int, char*));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strclen(const char *str, const char c);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strappend(char *base, const char *to_append, char side);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_indexchr(const char *str, const char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strinsert(char *dest, char *src, size_t pos);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcjoin(char const *s1, char c);
char				*ft_strpaste(char *dest, const char *src);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strtrim(char const *str);
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
char				*ft_strnewchr(size_t size, char c);
char				*ft_randstr(size_t n);
char				**ft_strsplit(char const *str, char c);
void				ft_strtabdel(char **t);

/*
** Case
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strupper(char *str);
char				*ft_strlower(char *str);

/*
** Integer
*/

int					ft_sqrt(int nb);
int					ft_intlen(int n);
int					*ft_inttabnew(size_t size);

/*
** Conversion
*/

int					ft_nblen_base(long long n, int base);
int					ft_unblen_base(unsigned long long n, int base);
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, int base);
char				*ft_itoa(int n);
char				*ft_ntoa_base(long long n, int base);
char				*ft_untoa_base(unsigned long long n, int base);
long				key_input(void);

/*
** List
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lstm, t_list *(*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));


/*
** Terminal
*/

int					term_raw(t_termios *get, int vtime, int vmin);

#endif
