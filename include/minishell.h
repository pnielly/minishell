/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:51:14 by user42            #+#    #+#             */
/*   Updated: 2020/12/15 12:55:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SINGLE 39
# define DOUBLE 34
# define EXPORT 0
# define UNSET 1
# define DF  "\033[0;m"
# define BLACK          "\033[1;30m"
# define RED            "\033[1;31m"
# define GR          "\033[1;32m"
# define YELLOW         "\033[1;33m"
# define B           "\033[1;34m"
# define P         "\033[1;35m"
# define CYAN           "\033[1;36m"
# define GREY           "\033[1;37m"
# define WHITE "\033[;0m"
# define BLINK "\e[5m"
# define B_YE  "\e[38;5;11m"
# define ORANGE "\e[38;5;209m"
# define BOLD_GR "\e[1;92m"
# define PINK "\e[38;5;198m"
# define BLUE "\e[38;5;21m"

# define WRONG_ARG 22
# define VAL_ERROR ": not a valid identifier"
# define BIN_ERROR ": No such file or directory"
# define CMD_NO_FD ": command not found"

# define ENV_USER "USER="
# define ENV_PATH "PATH="
# define ENV_HOME "HOME="
# define ENV_PWD "PWD="
# define ENV_OLDPWD "OLDPWD="
# define BASIC_ENV_PATH "PATH=/bin:/usr/bin:/sbin:/usr/sbin"
# define BASIC_ENV_USER "USER=maobe"
# define HOME_ERROR "%s/!\\ NO HOME DEFINE /!\\ \n%s"
# define CD_HOME_ERR "[-] Home env variable is not define"

# define SPACE " \f\t\n\r\v"

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>

# include "libft.h"

typedef struct	s_mini
{
	char		*line;
	char		**env;
	int			last_pid;
	int			ctrl_c;
	int			is_cmd;
	int			last_return;
	int			exit_v;
	int			cmd_is_bin;
	int			newfd;
	char		*file;
	int			p[2];
	int			fst_init;
	int			has_sub;
	int			has_env_i;
	int			is_pipe;
	int			fd[2];
	int			status;
	int			nb_pipes;
}				t_mini;

void			ft_export_alone(char **arr, t_mini *sh);
int				len_var_name(char *var);
int				is_new_var(char *s, char **env);
void			add_variables_in_env(t_mini *sh);
int				has_redirection_in_arr(char **arr);
void			display_animals(char *ani, char *age);
int				empty_cmd(char **arr);
int				ft_forking(char **split_input, t_mini *sh);
void			sophie_la_girafe(int length);
char			**new_cmd(char **arr, int i, int j);
int				ft_manage_pipe(t_mini *sh, char **arr);
int				ft_error(char *str, int errno_value);
void			show_cat(void);
void			display_ascii_dude(void);
void			manage_signals(void);
void			manage_input(t_mini *sh);
void			ft_putendl(char *str);
void			ft_envadd(char *expt, t_mini *sh);
void			env(t_mini *sh, char **arr);
void			pwd(t_mini *sh);
void			ft_cd(char **arr, t_mini *sh);
void			echo(char **arr);
char			*ft_find_env(char *name, char **env);
size_t			ft_tablen(char **tab);
int				cd_to_current_dir_opt(char **av);
void			cd_to_current_dir(t_mini *sh);
void			change_dir(t_mini *sh, char *p);
void			change_env_var_value(char **env, char *new_p,
				char *var, t_mini *s);
void			go_to_required_directory(t_mini *sh, char *dest, char *src);
void			cd_error_message(char *str);
void			ft_export(char **arr, t_mini *sh);
int				has_invalid_char_in_env_name(char *str);
int				has_equal_sign(char *s);
void			ft_tabfree(char **tab);
void			show_export_error_message(char *s);
void			unset(char **arr, t_mini *sh);
int				get_matched_var_in_env(char **env, char *var);
void			cpy_env(t_mini *sh, char **env);
char			*find_full_binary_path(char *cmd, t_mini *sh);
int				print_prompt(t_mini *sh);
void			check_quote_close(char **arr, t_mini *sh);
void			show_key_error_message(int key, char *s);
void			show_welcome_mes(void);
void			replace_var_sub_by_true_value(char **arr, t_mini *sh);
char			*get_full_cmd_path(char *cmd, t_mini *sh);
void			ft_exit(char **split_input, t_mini *sh);
void			ft_signal(t_mini *sh);
void			init_sh(char **env, t_mini **sh);
t_mini			**get_sh(void);
int				get_nb_digit(int nb);
void			replace_question_mark_by_exit_value(char **str, int j, int n);
char			*extract_cmd_from_bin_cmd(int index, char *cmd);
char			*manage_binary_cmd(char *cmd, t_mini *sh);
int				get_bin_directory_index(char *str);
void			show_error_message(char *cmd, char *err, t_mini *sh);
char			*check_cmd_and_return_full_bin_path(char *cmd, char **bin_path);
int				is_binary_path(char *s);
void			free_var(t_mini **sh);
int				parent_process(t_mini *sh);
int				child_process(char **split_input, t_mini *sh);
void			init_env_var(t_mini *sh);
int				is_syntax_error(char *s, t_mini *sh);
int				has_multi_valid_arg(char **arr);
char			*extract_target_path(char **arr);
int				is_go_home_opt(char **arr, t_mini *sh);
int				next_char_is_question_mark(char *s, int i);
void			manage_question_mark(char **str, int *i, int exit_value);
char			*varname_is_in_env(char *s, t_mini *sh);
int				get_varname_len(const char *s, int i);
void			replace_var_by_value(char **s, int *i, char *v, t_mini *sh);
char			*get_value_from_env(char *s, t_mini *sh);
void			manage_substitution_in_str(t_mini *sh, char **str);
int				replace_var_condition(t_quo *q, char *s, int i);
char			**check_for_redir(char **arr, t_mini *sh, int i);
int				split_and_execute(char *str, char *sep, int i, t_mini *sh);
int				ft_max(int a, int b);
int				sep_in_str_is_invalid(char *str, char c);
void			exec_not_build_in_cmd(char *bin_path, char **arr, t_mini *sh);
int				free_empty_tab(char **arr);
int				redirection_syntax_error(char *s);
int				valid_red_char_combinaison(char *cmd, int i);
void			redirection_message_err(char c);
void			redirection_message_err_2(void);
int				is_redir_char(const char c);
int				redir_in_str(const char *s);
int				has_pluseur_red_char(char *cmd, int i);
int				has_mix_red_char(char *cmd, int i);
int				has_only_red_char(char *cmd, int i);
void			ft_cold_quit(int sig);
int				cmd_is_in_bin_dir(char *bin_dir, char *cmd);
void			print_sort_env(char **env, t_mini *sh);
void			replace_var_value(char *s, char **env);
void			manage_shellvl(t_mini *sh);
void			unset_var_recpy_env(char *name, t_mini *sh);
int				len_var_name(char *var);
int				is_new_var(char *s, char **env);

#endif
