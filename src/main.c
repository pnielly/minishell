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
** Analysis of cmds : 1. builtin? 2. executable? 3. other?
*/

char	**ft_run(char *cmd, char **env)
{
	char	**args;
	char	*tmp;
	int	i;

	if (!cmd)
		return (env);
	args = ft_split_inc(cmd, SPACE);
	i = -1;
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

char	**ft_redirection(char *s)
{
	char	c;
	// < , > , >> , |
	while (c = ft_strpbrk(s, "<>|"))
	{
		...
	}
// CALL FT_RUN WITH THE OUTPUT (WILL SPLIT WITH " ")
}

/*
** ft_parse() splits the cmd according to sep : ";", then "| > < >>", then " "
** and sends the output to manage_cmd().
*/

char	**ft_parse(char *line, char **env, char sep)
{
	int	j;
	char	**cmd;
// SPLIT WITH ;
	cmd = ft_split_exc(line, sep);
	j = 0;
	while (cmd[j])
	{
		if (ft_redirection(cmd[j++]))
			return (NULL);
	}
}

/*
** Checking absence of lonely quotation mark (either ' (->sq) or " (-> dq))
*/

int	check_syntax(char *s, int sq, int dq, int i)
{
	while (!(s[i] == '\'' && !dq) && !(s[i] == '\"' && !sq) && s[i])
		i++;
	if (s[i] == '\'' && !dq)
		sq = 1 - sq;
	if (s[i] == '\"' && !sq)
		dq = 1 - dq;
	if (s[i])
		return (check_syntax(s, sq, dq, i + 1));
	return (sq + dq);
}

/*
** Malloc and copy my own env
** Note : the function used is ft_envadd : it copies the env and adds an element 
** (hence expt == NULL here)
*/


char	**ft_envadd(char **envp, char *expt)
{
	int	i;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	if (expt != NULL)
		i++;
	if (!(env = malloc(sizeof(char *) * (i + 1))))
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
** ft_read_cmd() simply reads the cmd
** from the relevant file descriptor
*/

int	ft_read_cmd(int fd, char **env)
{
	int	status;
	char	*line;
	
	status = 1;
	while (status)
	{
		ft_putstr("> ");
		line = NULL;
		get_next_line(fd, &line);
		if (check_syntax(line, 0, 0, 0))
		{
			ft_putstr(strerror(WRONG_ARG));
			continue;
		}
		env = ft_parse(line, env, ';');
		status = env ? 1 : 0;
		free(line);
	}
	return (0);
}

/*
** Read and tokenize cmd line based on ";"
*/

int	main(int ac, char **av, char **envp)
{
	char	**env;

	(void)ac;
	(void)av;
	display_ascii_dude();
	env = ft_envadd(envp, NULL);
	ft_read_cmd(0, env);
	return (0);
}
