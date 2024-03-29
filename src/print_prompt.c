/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:43:48 by pnielly           #+#    #+#             */
/*   Updated: 2020/12/13 16:43:49 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	show_smile_face(void)
{
	char	*s;

	s = "\U0001F600";
	ft_printf("%s[%s] ", GR, s);
}

static void	show_sad_face(void)
{
	char	*s;

	s = "\U0001F61E";
	ft_printf("%s[%s] ", RED, s);
}

int			print_prompt(t_mini *sh)
{
	char	*user;

	if (!sh->ctrl_c)
	{
		if (!sh->last_return)
			show_smile_face();
		else
			show_sad_face();
		user = ft_find_env(ENV_USER, sh->env);
		if (!user)
			user = "maobe";
		ft_printf("%sx%sX%sx %s%s", GR, YELLOW, RED, "\033[0;44m", user);
		ft_printf("%s %sx%sX%sx%s> ", "\033[32;0m", GR, YELLOW, RED, WHITE);
	}
	else
		sh->ctrl_c = 0;
	return (1);
}
