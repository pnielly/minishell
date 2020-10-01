#include "minishell.h"
#include "utils.h"

char	*ft_search_var(char *var, char **env)
{
	int	i;
	char	*ret;

	i = -1;
	ret = NULL;
	while (env[++i])
		if (!ft_strncmp(var, env[i], ft_strlen(var)))
			ret = env[i] + ft_strlen(var) + 2;
	return (ret);
}

void	ft_update_oldpwd(char **env)
{
	char	od[PATH_MAX + 1];
	char	**oldpwd;

	ft_bzero(od, PATH_MAX);
	ft_strcat(od, "export OLDPWD=");
	ft_strcat(od, ft_search_var("PWD", env));
	oldpwd = ft_split_inc(od, SPACE);
	bt_export(oldpwd, env);
	ft_tabfree(oldpwd);
	return ;
}

char	**bt_cd(char **args, char **env)
{
	char	path[PATH_MAX + 1];

	printf("YOYOYO\n");
	ft_bzero(path, PATH_MAX);
	if (ft_tablen(args) > 2)
	{
		printf("%s\n", strerror(WRONG_ARG));
		return (env);
	}
	else if (ft_tablen(args) == 1 || !ft_strcmp(args[1], "~"))
	{
		ft_strcat(path, "/");
		ft_strcat(path, ft_search_var("HOME", env));
	}
	else if (!ft_strcmp(args[1], "-") || !ft_strcmp(args[1], "~-"))
	{
		if (!ft_strcmp(args[1], "-"))
			ft_putendl(ft_search_var("OLDPWD", env));
		ft_strcat(path, "/");
		ft_strcat(path, ft_search_var("OLDPWD", env));
	}
	else
		ft_strcat(path, args[1]);
	printf("path = '%s'\n", path);
	ft_update_oldpwd(env);
	chdir(path);
	return (env);
}
