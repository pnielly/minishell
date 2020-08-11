#include "minishell.h"
#include "utils.h"

char	**bt_cd(char **args, char **env)
{
	if (ft_tablen(args) > 2)
	{
		printf("%s\n", strerror(WRONG_ARG));
		return (env);
	}
	if (ft_tablen(args) == 1)
		return (env);
	return (env);
}
