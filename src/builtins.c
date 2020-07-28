#include "minishell.h"

/*
** Commands names
*/

char	*bt_str(int i)
{
	char	*bt[BLTS + 1];

	bt[0] = "pwd";
	bt[1] = "exit";
	bt[2] = "echo";
	bt[3] = "env";
	bt[4] = NULL;
	return (bt[i]);
}

/*
** Commands functions
*/

char	**(*bt_ft(int i))(char **args, char **env)
{
	char	**(*bt_ft[BLTS + 1])(char **args, char **env);

	bt_ft[0] = &bt_pwd;
	bt_ft[1] = &bt_exit;
	bt_ft[2] = &bt_echo;
	bt_ft[3] = &bt_env;
	return (bt_ft[i]);
}
