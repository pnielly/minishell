#include "minishell.h"
#include "utils.h"

char **bt_pwd(char **args, char **env)
{
	char *buf;

	buf = ft_memalloc(PATH_MAX);
	if (!getcwd(buf, PATH_MAX))
		strerror(errno);
	else
	{
		ft_putstr(buf);
		ft_putchar('\n');
	}
	free(buf);
	return (env);
	(void)args;
}
