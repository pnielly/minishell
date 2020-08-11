#include "minishell.h"
#include "utils.h"

/*
 ** Launch executable/program
 */

int	ft_pgrm(char *exe, char **args, char **env)
{
	pid_t	pid;

	pid = fork();
	errno = 0;
	if (pid < 0)
		strerror(errno);
	else if (!pid)
		execve(exe, args, env) == -1 ? strerror(errno) : 0;
	else
		wait(&pid);
	return (1);
}

/*
 ** Checking absence of single quotation mark (either " or ')
 */

int	check_syntax(char *s)
{
	int	i;
	int	sl;
	int	dl;

	i = 0;
	sl = 0;
	dl = 0;
	while (s[i])
	{
		while (s[i] != '\'' && s[i] != '\"' && s[i])
			i++;
		if (s[i] == '\'')
		{
			sl = 1;
			while (s[i] != '\'' && s[i])
				i++;
			if (s[i] == '\'')
				sl = 0;
		}
		if (s[i] == '\"')
		{
			dl = 1;
			while (s[i] != '\"' && s[i])
				i++;
			if (s[i] == '\"')
				dl = 0;
		}
		i++;
	}
	return (dl + sl);
}

/*
 ** Analyse cmds : 1. builtin? 2. executable? 3. other?
 */

char	**ft_run(char *cmd, char **env)
{
	char	**args;
	char	*tmp;
	int	i;

	if (!cmd)
		return (env);
	args = ft_split(cmd, SPACE);
//	check_syntax(cmd) ? printf("%s\n", strerror(WRONG_ARG)) | return (env) : 0;
	if (check_syntax(cmd))
	{
		printf("%s\n", strerror(WRONG_ARG));
		return (env);
	}
	free(cmd);
	cmd = NULL;
	tmp = ft_strrmv(args[0], SPACE);
	free(args[0]);
	args[0] = tmp;
	i = -1;
	while (++i < BLTS)
		if (!ft_strcmp(args[0], bt_str(i)))
			return ((*bt_ft(i))(args, env));
	if (args[0][0] == '.' && args[0][1] == '/')
		ft_pgrm(args[0], args, env);
	return (env);
}

/*
 ** Malloc and copy my own env
 */


char	**ft_envadd(char **envp, char *expt)
{
	int	i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	if (!(env = malloc(sizeof(char *) * (i + 1 + 1))))
		return (NULL);
	i = -1;
	while (envp[++i])
		env[i] = ft_strdup(envp[i]);
	if (expt != NULL)
		env[i++] = ft_strdup(expt);
	env[i] = NULL;
	return (env);
}

/*
 ** Read and tokenize cmd line
 */

int	main(int ac, char **av, char **envp)
{
	int	status;
	char	**cmds;
	char	*line;
	int	j;
	char	**env;

	(void)ac;
	(void)av;
	display_ascii_dude();
	env = ft_envadd(envp, NULL);
	status = 1;
	while (status)
	{
		ft_putstr("> ");
		line = NULL;
		get_next_line(0, &line);
		cmds = ft_strtok(line, ";");
		j = 0;
		while (cmds[j])
			env = ft_run(cmds[j++], env);
		status = env ? 1 : 0;
		free(cmds);
		free(line);
	}
	return (0);
}
