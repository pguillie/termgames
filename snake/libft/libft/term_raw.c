#include "libft.h"

int		term_raw(t_termios *get, int vtime, int vmin)
{
	t_termios	set;

	if (tcgetattr(0, get) < 0)
		return (ft_error("Unable to get the termios structure", NULL, NULL));
	set = *get;
	set.c_iflag &= ~(IMAXBEL | IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR
			| IGNCR | IXON);
	set.c_oflag &= ~OPOST;
	set.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	set.c_cflag &= ~(CSIZE | PARENB);
	set.c_cflag |= CS8;
	set.c_cc[VTIME] = vtime;
	set.c_cc[VMIN] = vmin;
	if (tcsetattr(0, TCSANOW, &set) < 0)
		return (ft_error("Unable to set raw termios structure", NULL, NULL));
	return (0);

}
