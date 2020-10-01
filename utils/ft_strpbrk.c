#include "utils.h"

/*
** ft_strpbrk() locates the first occurence in the string s of any byte in the string accept
*/

char	*ft_strpbrk(const char *s, const char *accept)
{
	int	i;
	char	*ptr;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(accept, s[i]))
			return (ptr = (char *)s + i);
		i++;
	}
	return (NULL);
}
