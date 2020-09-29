#include "utils.h"

int		ft_putstr(char *str)
{
	int	i;
	int	ret;

	if (!str)
		return (0);
	i = -1;
	ret = 0;
	while (str[++i])
		ret += ft_putchar(str[i]);
	return (ret);
}
