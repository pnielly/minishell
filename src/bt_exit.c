#include "minishell.h"
#include "utils.h"

char	**bt_exit(char **args, char **env)
{
	ft_tabfree(env);
	env = NULL;
	return (env);
	(void)args;
}
