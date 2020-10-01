#include "minishell.h"

/*
** bt_env will display all env variables except "$$", "$!" and "$?"
*/

char	**bt_env(char **args, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (ft_strchr(env[i], '='))
			if (!(ft_strchr("$?!", env[i][0]) && env[i][1] == '='))
				ft_putendl(env[i]);
	}
	return (env);
	(void)args;
}
