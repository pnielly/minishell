#include "minishell.h"
#include "utils.h"

char	**bt_ls(char **args, char **env)
{
	DIR *dir;
	struct dirent *sd;

	if (!(dir = opendir(".")))
		printf("%s\n", strerror(errno));
	else
	{
		while ((sd = readdir(dir)) != NULL)
			ft_putendl(sd->d_name);
	}
	closedir(dir);
	return (env);
	(void)args;
}
