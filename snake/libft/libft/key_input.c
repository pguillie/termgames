#include "libft.h"

long	key_input(void)
{
	char	buff[6];
	long	ret;
	int		i;

	ret = 0;
	i = 6;
	ft_memset(buff, 0, 6);
	read(0, buff, 6);
	while (i--)
		ret += ret * 256 + buff[i];
	return (ret);
}
