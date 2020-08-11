#include "minishell.h"
#include "utils.h"

char	**bt_help(char **args, char **env)
{
	(void)env;
	(void)args;
	ft_putendl("List of available builtins :");
	ft_putendl("cd");
	ft_putendl("pwd");
	ft_putendl("echo");
	ft_putendl("env");
	ft_putendl("export");
	ft_putendl("unset");
	ft_putendl("sophie : type \"sophie\" followed by the age of sophie la girafe\n-- Example : \"> sophie 10\"");
	ft_putendl("exit");
	return (env);
}
