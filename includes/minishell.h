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
# include <dirent.h>

/*
** Macros
*/

# define SPACE " \f\t\n\r\v"

/*
** # of builtins
*/

# define BLTS 10

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
char	**bt_export(char **args, char **env);
char	**bt_unset(char **args, char **env);
char	**bt_cd(char **args, char **env);

/* Other useful builtins (not mandatory) */
char	**bt_sophie(char **args, char **env);
char	**bt_help(char **args, char **env);
char	**bt_ls(char **args, char **env);

/* Other useful functions */
char	**ft_envadd(char **envp, char *expt);
char	**ft_envsub(char **envp, char *unset);

#endif
