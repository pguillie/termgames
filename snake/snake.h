#ifndef SNAKE_H
# define SNAKE_H

# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <time.h>
# include "libft.h"

# define UP 4316599
# define DO 4382648
# define RI 4448697
# define LE 4514746

typedef struct		s_coord2d
{
	int				x;
	int				y;
}					t_coord2d;

typedef struct		s_snbody
{
	t_coord2d		p;
	struct s_snbody	*next;
}					t_snbody;

typedef struct		s_snake
{
	char			term_buffer[2048];
	char			cm[512];
	int				dir;
	t_coord2d		x;
	t_coord2d		wsz;
	t_snbody		*h;
	t_snbody		*l;
	t_termios		backup;
 }					t_snake;

#endif
