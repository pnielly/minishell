#include "minishell.h"
#include "utils.h"


/*
 ** Looking for var (for ex : $USER) within env and print it ; otherwise do nothing
 */

void	ft_print_var(char **args, int i, int j, char **env)
{
	char	*var;
	int	k;

	printf("PRINTF VAR");
	k = ++j;
	while (!ft_strchr("$' ", args[i][k]) && args[i][k])
		k++;
	var = ft_substr(args[i], j, k - j);
	k = -1;
	while (env[++k])
	{
		if (!ft_strncmp(var, env[k], ft_strlen(var)) && env[k][ft_strlen(var) + 1] == '=')
			write(1, env[k] + ft_strlen(var) + 1, ft_strlen(env[k]) - ft_strlen(var));
	}
	free(var);
	var = NULL;
	return ;
}


/*
 ** Checking quotes --> quote[0] : signle quote opened / quote[1] : double quote
 */

char	**bt_echo(char **args, char **env)
{
	int	i;
	int	j;
	int	quote[2];

	if (ft_tablen(args) <= 1)
	{
		write(1, "\n", 1);
		return (env);
	}
	i = 0;
	if (!ft_strncmp(args[1], "-n", 2))
		i = 1;
	printf("caca");
	quote[0] = 0;
	quote[1] = 0;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (args[i][j] == '\'' && quote[1])
				write(1, &args[i][j], 1);
			if (args[i][j] == '\"' && quote[0])
				write(1, &args[i][j], 1);
			if ((args[i][j] == '$' && quote[0]))
				write(1, &args[i][j], 1);
			if (!ft_strchr("\'\"$", args[i][j]))
				write(1, &args[i][j], 1);
			if (args[i][j] == '\'' && quote[0])
				quote[0] = 0;
			if (args[i][j] == '\'' && !quote[1])
				quote[0] = 1;
			if (args[i][j] == '\"' && quote[1])
				quote[1] = 0;
			if (args[i][j] == '\"' && !quote[0])
				quote[1] = 1;
			if (args[i][j] == '$' && !quote[0])
			{
				printf("BOUH");
				ft_print_var(args, i, j, env);
				j++;
				while (!ft_strchr("$' ", args[i][j]))
					j++;
				j--;
			}
		}
	}
	if (ft_strncmp(args[1], "-n", 2))
		write(1, "\n", 1);
	return (env);
	(void)args;
}
