/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinwang <xinwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 23:51:34 by xinwang           #+#    #+#             */
/*   Updated: 2020/12/13 17:37:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_backslash_zero(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '_')
			ft_putchar(0);
		else
			ft_putchar(s[i]);
	}
}

int		print_value(char **value, int is_backslash_zero)
{
	int	count;

	count = ft_strlen(*value);
	if (is_backslash_zero)
		print_backslash_zero(*value);
	else
		ft_putstr(*value);
	free_p_str(value);
	return (count);
}
