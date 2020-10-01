#include "utils.h"

/*
** ft_strtrim() removes all leading or trailing char belonging to "sep"
*/

char	*ft_strtrim(char *s, char *sep)
{
	int	i;

	i = 0;
	while (ft_strchr(sep, s[i]))
		i++;
	s += i;
	while (s[i])
		i++;
	i--;
	while (ft_strchr(sep, s[i]))
		i--;
	i++;
	s[i] = '\0';
	return (s);
}
