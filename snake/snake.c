#include "snake.h"

static t_snbody	*newsnbody(t_snbody *next, int dir, t_coord2d wsz)
{
	t_snbody	*new;
	if (!(new = (t_snbody*)ft_memalloc(sizeof(t_snbody))))
		return (NULL);
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
	t_termios	set;
	char		*termtype;
	int			success;

	if (!(termtype = getenv("TERM")))
		return (ft_error(prg, "`TERM'", "environment variable not found"));
	success = tgetent(s->term_buffer, termtype);
	if (success < 0)
		return (ft_error(prg, "Could not access the termcap data base", NULL));
	else if (success == 0)
		return (ft_error(prg, termtype, "terminal type not defined"));
	if (snake_win(prg, s))
		return (1);
	success = 0;
	while (success < 4)
		s->h = newsnbody(success++ ? s->h : NULL, (s->dir = RI), s->wsz);
	if (term_raw(&(s->backup), 1, 0))
		return (1);
	return (0);
}

static void		snake_loop(t_snake *s, long *key)
{
	s->h = newsnbody(s->h, ((*key == UP && s->dir != DO)
		|| (*key == DO && s->dir != UP) || (*key == RI && s->dir != LE)
		|| (*key == LE && s->dir != RI)) ? (s->dir = *key) : s->dir, s->wsz);
	s->l = s->h;
	ft_putstr(tgetstr("cl", NULL));
	ft_putstr(tgoto(tgetstr("cm", NULL), (s->x.x %= s->wsz.x), (s->x.y %= s->wsz.y)));
	ft_putchar('x');
	while (s->l)
	{
		if (s->h != s->l && s->h->p.x == s->l->p.x && s->h->p.y == s->l->p.y)
			*key = -1;
		ft_putstr(tgoto(tgetstr("cm", NULL), s->l->p.x, s->l->p.y));
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
	ft_putstr(tgetstr("ti", NULL));
	ft_putstr(tgetstr("vi", NULL));
	key = 0;
	while (key >= 0 && !snake_win("snake", &s) && (key = key_input()) != 27)
		snake_loop(&s, &key);
	ft_putstr(tgetstr("te", NULL));
	ft_putstr(tgetstr("ve", NULL));
	if (tcsetattr(0, TCSANOW, &(s.backup)) < 0)
		return (ft_error("snake", "Unable to restore termios structure", NULL));
	while (s.h)
	{
		s.l = s.h->next;
		free(s.h);
		s.h = s.l;
	}
	return (0);
}
