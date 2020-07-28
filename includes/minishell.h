#ifndef MINISHELL_H
# define MINISHELL_H

/*
** Headers
*/

# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "utils.h"
# include <limits.h>

/*
** Macros
*/

# define SPACE " \t\n\r\v"

/*
** # of builtins
*/

# define BLTS 4

/*
** errno index
*/

# define WRONG_ARG 22

/*  List of buitin shell commands */
char	*bt_str(int i);

char	**(*bt_ft(int i))(char **args, char  **env);

/* Function declarations for buitin shell commands */
char	**bt_pwd(char **args, char **env);
char	**bt_exit(char **args, char **env);
char	**bt_echo(char **args, char **env);
char	**bt_env(char **args, char **env);

#endif
