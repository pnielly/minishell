#include "utils.h"

int	ft_putstr_until(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		ft_putchar(s[i++]);
	return (i);
}
