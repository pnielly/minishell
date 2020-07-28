#include "minishell.h"

char	**bt_env(char **args, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		ft_putendl(env[i]);
	}
	return (env);
	(void)args;
}
