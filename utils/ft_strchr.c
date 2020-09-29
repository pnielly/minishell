#include "utils.h"

char	*ft_strchr(char const *s, int c)
{
	int	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		ptr = (char *)s + i;
	return (ptr);
}
