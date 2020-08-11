
#include "minishell.h"
#include "utils.h"

char	**ft_envsub(char **envp, char *unset)
{
	int	i;
	int	j;
	int	k;
	char	**env;

	i = 0;
	while (envp[i])
		i++;
	if (!(env = malloc(sizeof(char *) * (i - 1 + 1))))
		return (NULL);
	j = 0;
	k = 0;
	while (k < i)
	{
		if (!ft_strncmp(unset, envp[j], ft_strlen(unset)))
			j++;
		if (!envp[j])
			break ;
		env[k++] = ft_strdup(envp[j++]);
		if (!envp[j])
			break ;
	}
	env[k] = NULL;
	return (env);
}

static int	does_exist(char **env, char *var)
{
	int	i;
	int	check;

	i = -1;
	check = 1;
	while (env[++i])
	{
		if (!ft_strncmp(var, env[i], ft_strlen(var)) && env[i][ft_strlen(var)] == '=')
			check = 0;
	}
	return (check);
}

char	**bt_unset(char **args, char **env)
{
	char	**tmp;

	if (ft_tablen(args) > 2)
	{
		printf("%s\n", strerror(WRONG_ARG));
		return (NULL);
	}
	if (ft_tablen(args) == 1)
		return (env);
	if (does_exist(env, args[1]))
		return (env);
	tmp = ft_envsub(env, args[1]);
	ft_tabfree(env);
	env = tmp;
	return (env);
}
