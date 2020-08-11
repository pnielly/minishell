#include "utils.h"

int	ft_atoi(char *s)
{
	int	i;
	int	sign;
	int	res;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	res = 0;
	while (!ft_strchr("0123456789", s[i]) && s[i])
		i++;
	if (s[i] && i > 0)
	{
		if (s[i - 1] == '-')
			sign = -1;
	}
	while (ft_strchr("0123456789", s[i]) && s[i])
		res = res * 10 + s[i++] - 48;
	return (res * sign);
}
