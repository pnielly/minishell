#include "utils.h"

void	ft_tabfree(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		tab[i] = NULL;
		free(tab[i++]);
	}
	free(tab);
	return ;
}
