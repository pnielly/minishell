
#include "minishell.h"
#include "utils.h"

/*
** If the var name is already exported but the new export doesn't have a value, no modif is done
*/

int	ft_nomodif(char **env, char *var)
{
	int	i;
	int	check1;
	int	check2;

	i = 0;
	check1 = 1;
	check2 = 1;
	while (env[i])
	{
		if (!ft_strncmp(env[i], var, ft_strlen(var)) && env[i][ft_strlen(var)] == '=')
			check1 = 0;
		i++;
	}
	if (!ft_strchr(var, '='))
		check2 = 0;
//	printf("1 = %d et 2 = %d\n", check1, check2);
	return (check1 + check2);
}

/*
**	Here ft_envsub is used to remove any duplicate (if the var already exists in env)
**	Note : if you call "export" without arg, you'll get the output of env with "declare -x"
*/

char	**bt_export(char **args, char **env)
{
	char	**tmp0;
	char	**tmp1;
	int	i;
	char	*ptr;

	if (ft_tablen(args) > 2)
	{
		ft_putstr(strerror(WRONG_ARG));
		return (env);
	}
	if (ft_tablen(args) == 1)
	{
		i = 0;
		while (env[i])
		{
			ft_putstr("declare -x ");
			ft_putstr_until(env[i], '=');
			ft_putstr("=\"");
			ptr = ft_strchr(env[i++], '=');
			if (ptr)
				ft_putstr(ptr + 1);
			ft_putendl("\"");
		}
		return (env);
	}
	if (!ft_nomodif(env, args[1]))
		return (env);
	tmp0 = ft_envsub(env, args[1]);
	tmp1 = ft_envadd(tmp0, args[1]);
	ft_tabfree(env);
	ft_tabfree(tmp0);
	env = tmp1;
	return (env);
}
