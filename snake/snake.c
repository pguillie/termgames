/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguillie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 11:06:10 by pguillie          #+#    #+#             */
/*   Updated: 2017/06/06 17:28:36 by pguillie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static t_snbody	*newsnbody(t_snbody *next, int dir, t_coord2d wsz)
{
	t_snbody	*new;

	if (!(new = (t_snbody*)ft_memalloc(sizeof(t_snbody))))
	{
		while (next)
		{
			new = next->next;
			free(next);
			next = new;
		}
		return (NULL);
	}
	new->p.x = ((next ? next->p.x : 0)
			+ (dir == RI ? 1 : 0) - (dir == LE ? 1 : 0)) % wsz.x;
	new->p.y = ((next ? next->p.y : 0)
			+ (dir == DO ? 1 : 0) - (dir == UP ? 1 : 0)) % wsz.y;
	if (new->p.x < 0)
		new->p.x = wsz.x - 1;
	if (new->p.y < 0)
		new->p.y = wsz.y - 1;
	new->next = next;
	return (new);
}

static int		snake_win(char *prg, t_snake *s)
{
	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	s->wsz.x = w.ws_col;
	s->wsz.y = w.ws_row;
	if (s->wsz.x < 5 || s->wsz.y < 3
			|| s->wsz.x * s->wsz.y < 420)
		return (ft_error(prg, "Window too small\r", NULL));
	return (0);
}

static int		snake_init(char *prg, t_snake *s)
{
	char		*termtype;
	int			i;

	if (!(termtype = getenv("TERM")))
		return (ft_error(prg, "`TERM'", "environment variable not found"));
	i = tgetent(s->term_buffer, termtype);
	if (i <= 0)
		return (ft_error(prg, i ? E_TCBASE : termtype, i ? NULL : E_NOTERM));
	s->cl = tgetstr("cl", (char**)&s->term_str);
	s->cm = tgetstr("cm", (char**)&s->term_str);
	s->te = tgetstr("te", (char**)&s->term_str);
	s->ti = tgetstr("ti", (char**)&s->term_str);
	s->ve = tgetstr("ve", (char**)&s->term_str);
	s->vi = tgetstr("vi", (char**)&s->term_str);
	if (!s->cl || !s->cm || !s->te || !s->ti || !s->ve || !s->vi)
		return (ft_error(prg, "termcaps", "one or more termcaps are missing"));
	if (snake_win(prg, s))
		return (1);
	i = 0;
	while (i < 4)
		if (!(s->h = newsnbody(i++ ? s->h : NULL, RI, s->wsz)))
			return (ft_error(prg, "malloc", E_NOMEM));
	if (term_raw(&(s->backup), 1, 0))
		return (1);
	return (0);
}

static void		snake_loop(t_snake *s, long *key)
{
	s->h = newsnbody(s->h, ((*key == UP && s->dir != DO)
		|| (*key == DO && s->dir != UP) || (*key == RI && s->dir != LE)
		|| (*key == LE && s->dir != RI)) ? (s->dir = *key) : s->dir, s->wsz);
	if (!(s->l = s->h))
		*key = -2;
	ft_putstr(s->cl);
	ft_putstr(tgoto(s->cm, (s->x.x %= s->wsz.x), (s->x.y %= s->wsz.y)));
	ft_putchar('x');
	while (*key != -2 && s->l)
	{
		if (s->h != s->l && s->h->p.x == s->l->p.x && s->h->p.y == s->l->p.y)
			*key = -1;
		ft_putstr(tgoto(s->cm, s->l->p.x, s->l->p.y));
		ft_putchar('o');
		if (s->l->next && !s->l->next->next)
		{
			srand(time(NULL));
			if (s->h->p.x == s->x.x && s->h->p.y == s->x.y
				&& (s->x.x = rand() % s->wsz.x) + 1)
				s->x.y = rand() % s->wsz.y;
			else
				ft_memdel((void**)&s->l->next);
		}
		s->l = s->l->next;
	}
}

int				main(void)
{
	t_snake		s;
	long		key;

	if (snake_init("snake", &s))
		return (1);
	srand(time(NULL));
	s.x.x = rand() % s.wsz.x;
	s.x.y = rand() % s.wsz.y;
	ft_putstr(s.ti);
	ft_putstr(s.vi);
	s.dir = RI;
	key = 0;
	while (key >= 0 && !snake_win("snake", &s) && (key = key_input()) != 27)
		snake_loop(&s, &key);
	ft_putstr(s.te);
	ft_putstr(s.ve);
	if (tcsetattr(0, TCSANOW, &(s.backup)) < 0)
		return (ft_error("snake", "Unable to restore termios structure", NULL));
	while (key != -2 && s.h)
	{
		s.l = s.h->next;
		free(s.h);
		s.h = s.l;
	}
	return (key == -2 ? -1 : 0);
}
