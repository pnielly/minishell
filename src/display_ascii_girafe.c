/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ascii_girafe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnielly <pnielly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 16:40:19 by pnielly           #+#    #+#             */
/*   Updated: 2020/12/13 16:40:21 by pnielly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sophie_la_girafe(int length)
{
	if (length > 100)
	{
		ft_putendl("Sophie can't be that old !");
		length = 0;
	}
	else
		ft_printf("Sophie is a %d-year-old giraffe !\n", length);
	ft_putendl("       /\\/\\");
	ft_putendl("     _/   #\\_");
	ft_putendl("    |__    __|");
	ft_putendl("       @ @;");
	ft_putendl("      /oo #)");
	ft_putendl("      \\___/|");
	while (length-- > 0)
		ft_putendl("       	| #|");
	ft_putendl("       /   #\\");
	ft_putendl("      (# ^^ #)");
	ft_putendl("      /#| | |\\");
	ft_putendl("     / #| | |#\\");
	ft_putendl("    (_) (_|_)(_)");
	return ;
}
