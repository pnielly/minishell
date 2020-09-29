#include "utils.h"

int		ft_putendl(char *str)
{
	return (ft_putstr(str) + ft_putchar('\n'));
}
