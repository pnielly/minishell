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
	bt[4] = "export";
	bt[5] = "unset";
	bt[6] = "cd";
	bt[7] = "sophie";
	bt[8] = "help";
	bt[9] = "ls";
	bt[10] = NULL;
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
	bt_ft[4] = &bt_export;
	bt_ft[5] = &bt_unset;
	bt_ft[6] = &bt_cd;
	bt_ft[7] = &bt_sophie;
	bt_ft[8] = &bt_help;
	bt_ft[9] = &bt_ls;
	return (bt_ft[i]);
}
