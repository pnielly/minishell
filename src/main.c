/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:42:56 by pnielly           #+#    #+#             */
/*   Updated: 2020/12/13 16:42:57 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		exec_command(char **split_input, t_mini *sh)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(split_input[0], ""))
	{
		if (!ft_strcmp(split_input[0], "export") && !sh->is_pipe)
			ft_export(split_input, sh);
		else if (!ft_strcmp(split_input[0], "unset") && !sh->is_pipe)
			unset(split_input, sh);
		else if (!ft_strcmp(split_input[0], "cd") && !sh->is_pipe)
			ft_cd(split_input, sh);
		else if (!ft_strcmp(split_input[0], "exit"))
			ft_exit(split_input, sh);
		else
			ret = ft_forking(split_input, sh);
		return (ret);
	}
	else if (!ft_strcmp(split_input[0], "") && !sh->has_sub)
	{
		ft_putstr_fd("Command not found\n", 2);
		sh->last_return = 127;
		return (sh->last_return);
	}
	return (0);
}

int		split_and_execute_2(int last_ret, char **arr, char delim, t_mini *sh)
{
	if (delim == '|' && ft_tablen(arr) > 1)
	{
		sh->is_pipe = 1;
		last_ret = exec_command(arr, sh);
		sh->is_pipe = 0;
	}
	else if (delim == ' ')
	{
		check_quote_close(arr, sh);
		if (!sh->last_return)
		{
			replace_var_sub_by_true_value(arr, sh);
			if (!has_redirection_in_arr(arr))
			{
				delete_quotes_from_arr(arr, sh->has_sub);
				delete_slash_from_arr(arr);
			}
			last_ret = exec_command(arr, sh);
		}
	}
	return (last_ret);
}

int		split_and_execute(char *str, char *sep, int i, t_mini *sh)
{
	char	**arr;
	int		j;
	int		last_ret;

	j = -1;
	last_ret = 0;
	arr = ft_split_w_quotes(str, sep[i]);
	if (!arr || !arr[0])
		return (free_empty_tab(arr));
	if ((sep[i] == '|' && ft_tablen(arr) > 1) || sep[i] == ' ')
		last_ret = split_and_execute_2(last_ret, arr, sep[i], sh);
	else
	{
		while (arr[++j])
		{
			sh->last_return = split_and_execute(arr[j], sep, i + 1, sh);
			sh->exit_v = sh->last_return;
		}
	}
	if (last_ret > sh->last_return)
		sh->last_return = last_ret;
	ft_tabfree(arr);
	return (sh->last_return);
}

void	manage_input(t_mini *sh)
{
	char	*input;
	int		i;
	char	*sep;

	i = 0;
	sep = ";| ";
	input = NULL;
	ft_signal(sh);
	while (print_prompt(sh) && get_next_line(0, &input))
	{
		if (is_syntax_error(input, sh))
			continue ;
		sh->exit_v = sh->last_return;
		sh->line = input;
		sh->is_cmd = 1;
		sh->last_return = split_and_execute(sh->line, sep, i, sh);
		sh->is_cmd = 0;
		free_str(input);
		sh->has_sub = 0;
	}
	free_str(input);
}

int		main(int ac, char **av, char **env)
{
	t_mini	**sh;
	int		return_val;

	show_welcome_mes();
	sh = get_sh();
	init_sh(env, sh);
	if (!env[0])
	{
		(*sh)->has_env_i = 1;
		add_variables_in_env(*sh);
	}
	manage_shellvl(*sh);
	if (!ft_find_env(ENV_HOME, (*sh)->env))
		ft_printf(HOME_ERROR, RED, WHITE);
	manage_input(*sh);
	return_val = (*sh)->last_return;
	free_var(sh);
	return (return_val);
	(void)ac;
	(void)av;
}
