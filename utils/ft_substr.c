#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char*)ft_memalloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (len-- > 0 && s[i] != '\0')
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}